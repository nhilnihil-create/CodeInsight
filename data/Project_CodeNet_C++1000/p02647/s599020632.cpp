#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,K;
ll A[200005];
const ll max_n=1<<18;
ll dat1[2*max_n-1],dat2[2*max_n-1];
void add(ll a,ll b,ll x,ll k,ll l,ll r){
    if(a<=l&&r<=b){
        dat1[k]+=x;
    }
    else if(l<b&&a<r){
        dat2[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
ll sum(ll a,ll b,ll k,ll l,ll r){
    if(b<=l||r<=a) return 0;
    else if(a<=l&&r<=b) return dat1[k]*(r-l)+dat2[k];
    else{
        ll res=(min(b,r)-max(a,l))*dat1[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>K;
rep(i,N) cin>>A[i];
if(K>100){
	rep(i,N) cout<<N<<" ";
	cout<<endl;
	exit(0);
}
rep(k,K){
	memset(dat1,0,sizeof(dat1));
	memset(dat2,0,sizeof(dat2));
	rep(i,N){
		ll d=A[i];
		ll xleft=max((ll)0,i-d);
		ll xright=min(N-1,i+d);
		add(xleft,xright+1,1,0,0,N);
	}
	rep(i,N) A[i]=min(N,sum(i,i+1,0,0,N));
}
rep(i,N) cout<<A[i]<<" ";
cout<<endl;


}
	