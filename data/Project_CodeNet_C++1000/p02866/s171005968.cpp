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
    ll n,ans=1,m=0,D; cin>>n;
    vector<ll> cnt(n,0);
    rep(i,n){
        ll d; cin>>d;
        if(i==0) D=d;
        cnt[d]++;
        m=max(m,d);
    }
    if(D!=0 || cnt[0]!=1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        rep(j,cnt[i]) ans=ans*cnt[i-1]%mod;
    }
    cout<<(3*mod+ans)%mod<<endl;
}
