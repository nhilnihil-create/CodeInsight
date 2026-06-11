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
    int n; cin>>n;
    vector<int> a(n,0),b(n,0),c(n-1,0);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n-1) cin>>c[i];
    int ans=0;
    rep(i,n) ans+=b[i];
    rep(i,n-1){
        if(a[i+1]==a[i]+1) ans+=c[a[i]-1];
    }
    cout<<ans<<endl;
}