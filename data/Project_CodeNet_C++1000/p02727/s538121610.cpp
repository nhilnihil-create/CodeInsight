#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;


signed main(){
	ll x,y,a,b,c;
	cin >> x >>y>>a>>b>>c;
	vl pa(a),pb(b),pc(c);
	rep(i,0,a)cin>>pa[i];
	rep(i,0,b)cin>>pb[i];
	rep(i,0,c)cin>>pc[i];
	sort(all(pa)); reverse(all(pa));
	sort(all(pb)); reverse(all(pb));
	sort(all(pc)); reverse(all(pc));
	ll s=0,t=0,u=0;
	ll ans=0;
	rep(i,0,x+y){
		if(s<a && max({pa[s],pb[t],pc[u]})==pa[s]){
			ans+=pa[s];
			s++;
		}
		else if(t<b && max({pa[s],pb[t],pc[u]})==pb[t]){
			ans+=pb[t];
			t++;
		}
		else{
			ans+=pc[u];
			u++;
		}
	}
	if(s<=x && t<=y){
		cout<<ans<<endl;
		return 0;
	}
	if(x<s){
		for(ll i=s-1;i>=x;--i)ans-=pa[i];
		ll k=s-x;
		rep(i,0,k){
			if(t<b && max({pb[t],pc[u]})==pb[t]){
				ans+=pb[t];
				t++;
			}
			else{
				ans+=pc[u];
				u++;
			}
		}
		cout << ans << endl;
	}
	else{
		for(ll i=t-1;i>=y;--i)ans-=pb[i];
		ll k=t-y;
		rep(i,0,k){
			if(s<a && max({pa[s],pc[u]})==pa[s]){
				ans+=pa[s];
				s++;
			}
			else{
				ans+=pc[u];
				u++;
			}
		}
		cout << ans << endl;
	}

	

		return 0;
}
