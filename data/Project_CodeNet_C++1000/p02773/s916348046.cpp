#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

map<string,int>mp;
//mp[a]=aの出てくる回数
signed main(){
	int N;
	cin>>N;
	rep(i,N){
		string s;cin>>s;
		mp[s]++;
	}
	int mx=0;
	for(auto p:mp)mx=max(mx,p.second);
	for(auto p:mp){
		if(mx==p.second)cout<<p.first<<endl;
	}
}
