#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;

ll lcn[2010],rcn[2010],ans;

int main(){
    ll N,K;cin>>N>>K;
    ll a[2010];
    rep(i,0,N)cin>>a[i];
    rep(i,0,N){
        rep(j,i+1,N){
            if(a[i]>a[j])rcn[i]++;
        }
    }
    rep(i,0,N){
        rep(j,0,i){
            if(a[i]>a[j])lcn[i]++;
        }
    }
    rep(i,0,N){
        ans+=rcn[i]*((K*(K+1)/2)%1000000007);
        ans+=lcn[i]*((K*(K-1)/2)%1000000007);
        ans=ans%1000000007;
    }
    cout<<ans<<endl;
}




