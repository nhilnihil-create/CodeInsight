#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<double> a(n);

	rep(i, n){
		int d;
		cin >> d;
		a.at(i) = (double)1/d;
	}
	
	double sum = 0;
	rep(i, n) sum += a.at(i);

	cout << 1/sum << endl;
}
