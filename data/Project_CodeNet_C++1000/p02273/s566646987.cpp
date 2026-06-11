#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct vector{
	double x;
	double y;
};

void printVector(vector v){
		cout <<   v.x << " " << v.y  << endl;
}

void drawCock(vector begin, vector end, int depth){
	if(depth == 0){
		printVector(begin);
	}else{
		depth --;
		vector v[3];
		v[0].x = (begin.x * 2.0 + end.x)/3.0;
		v[0].y = (begin.y * 2.0 + end.y)/3.0;
		v[2].x = (begin.x + end.x * 2.0)/3.0;
		v[2].y = (begin.y + end.y * 2.0)/3.0;
		v[1].x = v[0].x + (v[2].x - v[0].x) * cos(M_PI/3.0) - (v[2].y - v[0].y) * sin(M_PI/3.0); 
		v[1].y = v[0].y + (v[2].x - v[0].x) * sin(M_PI/3.0) + (v[2].y - v[0].y) * cos(M_PI/3.0);

		drawCock(begin, v[0], depth);
		drawCock(v[0], v[1], depth);
		drawCock(v[1], v[2], depth);
		drawCock(v[2], end, depth);
		
	}
}

int main(){
	cout << fixed << setprecision(8);
	ios_base::sync_with_stdio(false);
	vector begin = {0,0};
	vector end = {100,0};
	int num;
	cin >> num;
	drawCock(begin,end,num);
	printVector(end);
	return 0;
}