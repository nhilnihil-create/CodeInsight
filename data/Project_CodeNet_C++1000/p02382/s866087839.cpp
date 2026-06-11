#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

void distance1(vector<int> x, vector<int> y)
{
	double sum = 0;
	int n = x.size();
	for(int i = 0; i < n; i++){
		sum += abs(x[i] - y[i]);
	} 
	cout << sum << endl;
}
void distance2(vector<int> x, vector<int> y)
{
	double dd = 0;
	int n = x.size();
	for(int i = 0; i < n; i++){
		dd += pow(abs(x[i] - y[i]), 2);
	}
	double d = sqrt(dd);
	cout << d << endl;
}
void distance3(vector<int> x, vector<int> y)
{
	double ddd = 0;
	int n = x.size();
	for(int i = 0; i < n; i++){
		ddd += pow(abs(x[i] - y[i]), 3);
	}
	double d = cbrt(ddd);
	cout << d << endl;
}
void distanceX(vector<int> x, vector<int> y)
{
	double max = 0;
	int n = x.size();
	for(int i = 0; i < n; i++){
		if(abs(x[i] - y[i]) > max){
			max = abs(x[i] - y[i]);
		}
	}
	cout << max << endl;
}
int main(void)
{	
	cout << fixed << setprecision(5);//?¨????

	int n;
	cin >> n;
	
	vector<int> x(n);
	vector<int> y(n);
	
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	
	distance1(x, y);
	distance2(x, y);
	distance3(x, y);
	distanceX(x, y);

	return 0;
}