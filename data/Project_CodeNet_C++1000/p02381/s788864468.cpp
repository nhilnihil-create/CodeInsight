#include <iostream>
#include <string>
//g++??????
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

double calc_average(vector<int> score)
{
	double sum = 0;
	int n = score.size();
	for(int i = 0; i < n; i++){
		sum += score[i];
	} 
	double m = sum / n;//?????????
	
	return m;	
}
double StandardDeviation(vector<int> score)
{
	int n = score.size();
	double sigma = 0;
	double m = calc_average(score);
	for(int i = 0; i < n; i++){
		sigma += pow(score[i] - m, 2);
	}
	
	double ss = sigma / n;
	
	return sqrt(ss);
}
int main(void)
{	
	cout << fixed << setprecision(4);//?¨????
	while(true){
		int n;
		cin >> n;
		
		if(n == 0){
			break;
		}
		vector<int> score(n);
		for(int i = 0; i < n; i++){
			cin >> score[i];
		}
		double r = StandardDeviation(score);
		cout << r << endl;
	}
	return 0;
}