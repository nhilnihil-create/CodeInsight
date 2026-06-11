#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
#include<vector>
using namespace std;

double ManhattanDistance(vector<int> x, vector<int> y){
	int n = x.size();
	double d = 0;
	for(int i = 0; i < n; i++) d += abs( x[i] - y[i] );
	return d;
}

double EuclidDistance(vector<int> x, vector<int> y){
	int n = x.size();
	double D = 0;
	for(int i = 0; i < n; i++) D += (x[i] - y[i]) * (x[i] - y[i]);
	return sqrt(D);
}

double CubeRootDistance(vector<int> x, vector<int> y){
	int n = x.size();
	double D = 0;
	for(int i = 0; i < n; i++) D += abs( (x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]) );
	return pow(D, 1.0 / 3.0);
}

double ChebyshevDistance(vector<int> x, vector<int> y){
	int n = x.size();
	double d = abs( x[0] - y[0] );
	for(int i = 1; i < n; i++) if( abs( x[i] - y[i] ) > d ) d = abs( x[i] - y[i] );
	return d;
}

vector<int> Enter(int n){
	vector<int> z;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		z.push_back(a);
	}
	return z;
}

int main(){
	int n;
	cin >> n;
	vector<int> x = Enter(n);
	vector<int> y = Enter(n);
	cout << fixed << setprecision(6)
		 << ManhattanDistance(x, y) << endl
		 << EuclidDistance(x, y) << endl
		 << CubeRootDistance(x, y) << endl
		 << ChebyshevDistance(x, y) << endl;
	return 0;
}