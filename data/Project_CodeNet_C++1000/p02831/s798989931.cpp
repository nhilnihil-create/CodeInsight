#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b; 
	cin >> a >> b;

	cout << lcm(a, b) << endl;

	return 0;
}

