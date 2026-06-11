#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

vector<ll> v[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t; cin >> s >> t;

	ll dp[26]={0};
	for(auto &x: t) dp[x-'a']=1;
	for(auto &x: s) dp[x-'a']=0;
	bool ok = 0;
	for(int i=0; i<26; ++i){
		if(dp[i]>0){
			ok = 1;
		}
		else continue;
	}

	if(ok){
		cout << -1 << endl;
		return 0;
	}		
	
	
	rep(i,0,sz(s),1){
		v[s[i]-'a'].push_back(i);
	}
	
	ll word = -1, last_pos = -1, ans = 0;
	rep(i,0,sz(t),1){
		auto ub = upper_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(), word);
		ll gg = ub-v[t[i]-'a'].begin();
		if(gg != sz(v[t[i]-'a'])){
			word = v[t[i]-'a'][gg];
			last_pos = v[t[i]-'a'][gg]+1;
		}
		else{
			++ans;
			word = -1;
			--i;
		}
	}
	cout << ans*sz(s)+last_pos << endl;
	return 0;
}
