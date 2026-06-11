//When I wrote this only God and I knew what it is
//Now, only The_Blitz knows...
#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	fastio;
	ll n; cin >> n;
	ll even = n / 2;
	ll odd = n - even;
	cout << fixed << setprecision(8) << odd * 1.0 / (even + odd) << endl;
	return 0;
}

