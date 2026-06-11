//When I wrote this only God and I knew what it is
//Now, only The_Blitz knows...
#pragma GCC optimize ("Ofast,unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

map< vector<int>, int> m;

int main(){
	fastio;
	int n; cin >> n;
	for(int i = 0; i < n; ++ i){
		string s; cin >> s;
		vector<int> x(26);
		for(char c: s) x[c -'a'] ++;
		m[x] ++;
	}
	ll ans = 0;
	for(auto x: m){
		ll r = x.ss;
		ans += r * (r - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}

