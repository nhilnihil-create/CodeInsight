#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define INF 1000000000000000LL
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	int N;
	cin>>N;
	map<string,int>mp;
	rep(i,1,N+1){
		string s,t;
		s=to_string(i);
		t.pb(s[0]);
		t.pb(s[s.size()-1]);
		mp[t]++;
		DBG(i,s,t,"");
	}
	ll ans=0;
	string u,v;
	rep(i,1,10){
		rep(j,1,10){
			u=to_string(i)+to_string(j);
			v=to_string(j)+to_string(i);
			DBG(i,j,u,v);
			ans+=mp[u]*mp[v];
		}
	}
	cout<<ans<<endl;
	return 0;
}
