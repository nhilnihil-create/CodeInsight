#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	double a;

	rep(i, n){
		int d;
		cin >> d;
		a += (double)1/d;	
	}

	cout << fixed << setprecision(10) << (double)1/a << endl;

	return 0;

}
