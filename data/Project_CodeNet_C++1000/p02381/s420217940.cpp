#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;

double StandardDeviation(vector<int> s){
	int n = s.size();
	double S = 0;
	double D = 0;
	for(int i = 0; i < n; i++) S += s[i];
	double m = S / n;
	for(int i = 0; i < n; i++) D += (s[i] - m) * (s[i] - m);
	double d = sqrt( D / n );
	return d;
}

vector<int> Enter(int n){
	vector<int> s;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		s.push_back(a);
	}
	return s;
}

int main(){
	vector<double> alpha;
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		vector<int> s;
		s = Enter(n);
		double d = StandardDeviation(s);
		alpha.push_back(d);
	}
	for(int i = 0; i < alpha.size(); i++) cout << fixed << setprecision(8) << alpha[i] << endl;
	return 0;
}