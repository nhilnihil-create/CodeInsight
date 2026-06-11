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

int main() {
    ll n,m,v,p,cnt,sum=0,vd; cin>>n>>m>>v>>p;
    ll ans=p;
    vector<ll> a(n,0),s(n+1,0);
    rep(i,n) cin>>a[i];
    sort(al(a)); reverse(al(a));
    rep(i,n){
        sum+=a[i]; s[i+1]=sum;
    }
    for(ll i=p;i<n;i++){
        if(a[p-1]>a[i]+m) break;
        vd=v-(n-i)-(p-1);
        if((a[i]+m)*(i-(p-1))-(s[i]-s[p-1])>=vd*m){
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
}