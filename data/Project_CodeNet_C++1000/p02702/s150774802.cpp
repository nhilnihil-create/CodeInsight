#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=2019;
int n, ss[200001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s, n=s.size();
	ss[n]=0;
	int mult=1;
	for (int i=n-1; ~i; --i) {
		ss[i]=(ss[i+1]+(s[i]-'0')*mult)%MOD;
		mult=mult*10%MOD;
	}
	map<int, int> oc;
	for (int i=0; i<=n; ++i) oc[ss[i]]++;
	ll ans=0;
	for (auto x : oc) ans+=1ll*x.second*(x.second-1)/2;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
