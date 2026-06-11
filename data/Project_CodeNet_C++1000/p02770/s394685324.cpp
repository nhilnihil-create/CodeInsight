//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll k,q; cin>>k>>q;
    vector<ll> d(k,0),td(k,0),sum(k+1,0);
    rep(i,k) cin>>d[i];
    rep(i,q){
        ll n,x,m,cnt=0; cin>>n>>x>>m;
        rep(i,k){
            td[i]=d[i]%m;
            sum[i+1]=td[i]+sum[i];
            if(td[i]==0) cnt+=(n-1+k-1-i)/k;
        }
        x%=m;
        ll s=x+(n-1)/k*sum[k]+sum[(n-1)%k];
        cout<<n-1-cnt-(s/m)<<endl;
    }
}
