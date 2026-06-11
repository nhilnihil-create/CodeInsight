//============================================================================
// Name        : KochCurve.cpp
// Author      : Ken
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589793238463;
const double cos_pi_3 = cos(PI/3.0);
const double sin_pi_3 = sin(PI/3.0);

struct Point{
	double x;
	double y;
};

void drawNewSegment(Point& P1, Point& P2, Point& P3, Point& P4, Point& P5){
	P3.x = (P1.x * 2 + P2.x * 1) / 3.0;
	P3.y = (P1.y * 2 + P2.y * 1) / 3.0;

	P5.x = (P1.x * 1 + P2.x * 2) / 3.0;
	P5.y = (P1.y * 1 + P2.y * 2) / 3.0;

	double P1_P3_x = P3.x - P1.x;
	double P1_P3_y = P3.y - P1.y;

	P4.x = P3.x + (P1_P3_x * cos_pi_3 - P1_P3_y * sin_pi_3);
	P4.y = P3.y + (P1_P3_x * sin_pi_3 + P1_P3_y * cos_pi_3);
}

vector<Point> drawNewCurve(vector<Point>& v){
	vector<Point> new_v;

	for(int i=0; i<v.size()-1; i++){
		Point P3, P4, P5;
		drawNewSegment(v.at(i), v.at(i+1), P3, P4, P5);

		new_v.push_back(v.at(i));
		new_v.push_back(P3);
		new_v.push_back(P4);
		new_v.push_back(P5);
		//new_v.push_back(v.at(i+1));
	}

	new_v.push_back(v.at(v.size()-1));

	return new_v;
}

void writePointVector(vector<Point>& v){
	for(int i=0; i<v.size(); i++){
		cout << setprecision(9) << v.at(i).x;
		cout << " ";
		cout << setprecision(9) << v.at(i).y << "\n";
	}
}

int main() {
	vector<Point> v;
	vector<Point> next_v;
	Point P1, P2;
	P1.x = 0;
	P1.y = 0;

	P2.x = 100;
	P2.y = 0;

	v.push_back(P1);
	v.push_back(P2);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		next_v = drawNewCurve(v);
		v = next_v;
	}

	writePointVector(v);

	return 0;
}

