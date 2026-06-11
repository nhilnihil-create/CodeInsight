#include <iostream>
#include <vector>
#include <math.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	typedef pair<int,int> pair_int;
	vector<pair_int> town(n);
	vector<double> roads_length;
	rep(i,n) {
		int x_1,y_1;
		cin >> x_1 >> y_1;
		town.at(i).first = x_1;
		town.at(i).second = y_1;
		for(int j = 0; j < i; j++){
			int x_2 = town.at(j).first;
			int y_2 = town.at(j).second;
			double dis = sqrt( ((x_1-x_2)*(x_1-x_2)) + ((y_1-y_2)*(y_1-y_2)) );
			roads_length.push_back(dis);
		}
	}
	/*
	int n_factorial = n;
	for(int i = 1; i < n; i++){
		n_factorial *= i;
	}

	int c_deno = n_factorial / (n*(n-1));
	int c_nume = 1;	
	
	//r-1の階乗
	for(int i = 0; i < n-2; i++){
		c_nume *= roads_length.size() - i -1;
	}
	
	int combination = c_nume / c_deno;
	*/
	double sum = 0;
	for(int i = 0; i < roads_length.size(); i++){
		sum += roads_length.at(i);
	}

	double ans = sum * (2/(double)n);
	printf("%.10f\n", ans);
	
	
}