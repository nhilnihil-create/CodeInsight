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
//or-> ||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	ll N;
	cin>>N;
	ll A[N+1];
	rep(i,0,N+1) cin>>A[i];
	ll minn[N+1],maxx[N+1];
	for(ll i=N;i>=0;i--){
		if(i==N){
			minn[i]=maxx[i]=A[i];
		}
		else{
			if(minn[i+1]%2==0){
				minn[i]=minn[i+1]/2+A[i];
			}
			else{
				minn[i]=minn[i+1]/2+A[i]+1;
			}
			maxx[i]=maxx[i+1]+A[i];
		}
	}

	ll ans;
	ans=0;
	if(minn[0]>1){
		ans=-1;
	}
	else{
		ans=1;//根
		ll prevv=1;
		rep(i,1,N+1){
			prevv=2*(prevv-A[i-1]);
			prevv=min(INF,prevv);
			DBG(i,prevv,maxx[i],"");
			ans+=min(prevv,maxx[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
