#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	string s[N];
	set<string> st;
	rep(i,N) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		st.insert(s[i]);
	}

	map<string, int> mp;
	for ( string p : st) mp[p] = 0;

	rep(i,N) mp[s[i]]++;
	ll ans = 0;
	for (string p : st) ans += (ll)mp[p]*(mp[p]-1)/2;
	cout << ans << endl;

	return 0;
}
