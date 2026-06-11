#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

void distance(vector<int> x, vector<int> y, int p)
{
	double sum = 0;
	int n = x.size();
	for(int i = 0; i < n; i++){
		sum += pow(abs(x[i] - y[i]), p);
	}
	sum = pow(sum, 1.0/p);
	cout << sum << endl;
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
	
	for(int i = 1; i <= 3; i++){
		int p = i;
		distance(x, y, p);
	}
	distanceX(x, y);

	return 0;
}