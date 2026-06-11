#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
/*２つの n 次元ベクトルが与えられるので、p がそれぞれ 1、2、3、∞ のミンコフスキー距離を求めるプログラムを作成してください。*/
using namespace std;
int main(){
	int n;
	double Dxy = 0;
	double Dxy2 = 0;
	double Dxy3 = 0;
	double DxyInf = 0;
	cin >> n;
	vector<double> x, y;
	for(int i = 0; i < n; i++){
		double tmpX;
		cin >> tmpX;
		x.push_back(tmpX);
	}
	for(int i = 0; i < n; i++){
		double tmpY;
		cin >> tmpY;
		y.push_back(tmpY);
	}
	for(int i = 0; i < n; i++){
		Dxy += (double)abs(x[i] - y[i]);	
		Dxy2 += pow(abs(x[i] - y[i]), 2);
		Dxy3 += pow(abs(x[i] - y[i]), 3);
		if(DxyInf < abs(x[i] - y[i])) DxyInf = abs(x[i] - y[i]);
	}
	cout << setprecision(20);	
	cout << Dxy << '\n';
	cout << pow(Dxy2, 1.0000 / 2.0000) << '\n';
	cout << pow(Dxy3, 1.0000 / 3.0000) << '\n';
	cout << DxyInf << '\n';
}

