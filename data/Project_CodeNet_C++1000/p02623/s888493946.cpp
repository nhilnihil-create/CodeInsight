//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n,m,k; cin>>n>>m>>k;
    vector<ll>asum(n+1),bsum(m+1);
    asum[0]=0;bsum[0]=0;
    rep(i,n){
        ll A; cin>>A;
        asum[i+1]=asum[i]+A;
    }
    rep(i,m){
        ll B; cin>>B;
        bsum[i+1]=bsum[i]+B;
    }
    ll ans=0;
    ll mx=0;
    for(int i=0;i<=n;i++){
        ll K=k-asum[i];
        if(K<0)break;
        for(int j=m;0<=j;j--){
            if(K-bsum[j]<0)continue;
            else{
                m=j;
                mx=j;
                break;
            }
        }
        ans=max(ans,i+mx);   
    }
    cout<<ans<<endl;


}












































































