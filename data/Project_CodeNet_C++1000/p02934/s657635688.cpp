#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<double> a(n);
	rep(i, n) cin >> a.at(i);

	double num = 0;
	rep(i, n) num += (double)1/a.at(i);

	cout << fixed << setprecision(10) << (double)1/num << endl;
	return 0;
}