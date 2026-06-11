#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair

ll N;
ll dp[200005];
ll cnt[10][15][15];
ll get_p(ll n){
	while(1){
		if(n/10==0) return n%10;
		n/=10;
	}
}
ll get_s(ll n){
	return n%10;
}
ll keta(ll n){
  ll ret=0;
  ll nn=n;
  while(1){
    nn/=10; 
    ret++;
    if(nn==0) break;
  }
  return ret;
}


int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep1(i,N+1){
	ll i_keta=keta(i);
	ll ip=get_p(i);
	ll is=get_s(i);
	ll add=0;
	if(ip==is){
		rep1(k,i_keta+1) add+=2*cnt[k][ip][is];
		add++;
	}else{
		rep1(k,i_keta+1){
			if(is==0) continue;
			if(k==i_keta&&is>ip) continue;
			add+=2*cnt[k][is][ip];
		}
	}
	dp[i]=dp[i-1]+add;
	cnt[i_keta][ip][is]++;
}
cout<<dp[N]<<endl;

}
	