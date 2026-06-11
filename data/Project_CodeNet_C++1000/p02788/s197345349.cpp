#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back
#define fs first
#define sc second

ll N,D,A;
ll ans;
ll X[200005];
P mst[200005];

const ll max_n=1<<18;
ll data[2*max_n-1],datb[2*max_n-1];
void add(ll a,ll b,ll x,ll k,ll l,ll r){
    if(a<=l&&r<=b){
        data[k]+=x;
    }
    else if(l<b&&a<r){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
ll sum(ll a,ll b,ll k,ll l,ll r){
    if(b<=l||r<=a) return 0;
    else if(a<=l&&r<=b) return data[k]*(r-l)+datb[k];
    else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>D>>A;
rep(i,N){
	cin>>mst[i].fs>>mst[i].sc;
	X[i]=mst[i].fs;
}
sort(mst,mst+N);
sort(X,X+N);
rep(i,N) add(i,i+1,mst[i].sc,0,0,N);
rep(i,N){
	ll H=sum(i,i+1,0,0,N);
	if(H<=0) continue;
	ll mid=mst[i].fs+D;
	ll in=upper_bound(X,X+N,mid+D)-X; 
	ll cnt=H/A;
	if(H%A!=0) cnt++;
	ans+=cnt;
	add(i,in,-A*cnt,0,0,N);
}
cout<<ans<<endl;

}
    
