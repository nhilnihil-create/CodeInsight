//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,m; cin>>n>>m;
    vector<ll>a(m); 
    vector<ll>f(n+1,0);
    rep(i,m){
        cin>>a[i];
        f[a[i]]=-1;
    }
    vector<ll>ans(n+1,0);
    if(f[1]==-1)ans[1]=0;
    else ans[1]=1;
    if(f[2]==-1)ans[2]=0;
    else ans[2]=1+ans[1];
    if(n<=2){
        cout<<ans[n]<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++){
        if(f[i]==-1)ans[i]=0;
        else {
            ans[i]=ans[i-2]+ans[i-1];
            ans[i]%=mod;
        }
    }
    cout<<ans[n]<<endl;

}

















































