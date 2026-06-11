#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	string s; cin >> s;
	int n = int (s.size());
	int m = (n-1)/2;
	int l = (n+3)/2;
	for(int i=0;i<m;i++){
		if(s[i]!=s[m-1-i]){
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i=l-1;i<n;i++){
		if(s[i]!=s[n-1-i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}