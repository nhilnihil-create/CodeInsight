//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2147483647
#define lli long long int
#define MOD 1000000007
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;



int main() {

	int n; cin >> n;
	vi fac;

	cout << n << ":";
	for (int i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			fac.pb(i);
			n = n / i;
		}
	}
	if (n != 1) fac.pb(n);
	
	for (int i  = 0; i < fac.size(); i++) {
		cout << " " << fac[i];
	}
	cout << endl;
	return 0;
}