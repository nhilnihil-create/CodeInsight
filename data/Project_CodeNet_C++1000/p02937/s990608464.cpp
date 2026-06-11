//SkGeN
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstring>
#include<climits>
#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
const int N = 2 * 1e5 + 10;
const ll inf = 1e18 + 100;
const ll mod = 1e9 + 7;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define brep(i,s,e) for(long long i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define DANGER std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve() {
	string s , t;
	cin>>s>>t;
	map<ll,vector<ll>> mp;
	ll len = s.size();
	for(int i = 0  ; i < s.size() ; i++) {
		mp[s[i]].pb(i);
	}

	ll val = 0 , ch = 0;
	if(mp.count(t[0]) == 0) {
		cout<<-1;
		return;
	} else {
		ch = mp[t[0]][0];
	}
	for(int i = 1; i < t.size() ; i++) {
		if(mp.count(t[i]) == 0) {
			cout<<"-1\n";
			return;
		} else {
			ll xx = upper_bound(mp[t[i]].begin() , mp[t[i]].end() , ch) - mp[t[i]].begin();
			//cout<<xx<<"\n";
			if(xx < mp[t[i]].size()) {
				ch = mp[t[i]][xx];
			} else {
				val += len;
				ch = mp[t[i]][0];
			}
		}
	}

	cout<<val + ch + 1<<"\n";
}
int main()
{
	DANGER;
	ll t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}
return 0;
}
//---->O ,,