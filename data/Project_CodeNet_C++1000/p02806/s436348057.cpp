#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<string, int> > df;
	for(int i = 0; i < n; i++){
		string s;
		int x;
		cin >> s >> x;
		df.pb(mp(s, x));
	}
	string t;
	cin >> t;
	ll ans = 0, mk = 0;
	for(int i = 0; i < df.size(); i++){
		if(mk)
			ans += df[i].second;
		if(df[i].first == t)
			mk = 1;
	}
	cout << ans << '\n';

}