//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    vector<ll>A(n+1);
    A[0]=0;
    vector<vector<ll>>f(10000,vector<ll>(2));
    ll cnt=0,ans=0;
    rep(i,n){
        cin>>a[i];
        rep(j,a[i]){
            cin>>f[cnt][0]>>f[cnt][1];
            cnt++;
        }
    }
    a.resize(cnt);
    rep(i,n){
        A[i+1]=A[i]+a[i];
    }
    cnt=0;
    for(int tmp=0;tmp<(1<<n);tmp++){
        bitset<15>b=tmp;
        bool jud=false;
        rep(i,n){
            if(!b.test(i)){
                cnt+=a[i];
                continue;
            }
            rep(j,a[i]){
                if(f[A[i]+j][1]==1){
                    if(!b.test(f[A[i]+j][0]-1)){
                        jud=true;
                    }
                }
                else if(f[A[i]+j][1]==0){
                    if(b.test(f[A[i]+j][0]-1)){
                        jud=true;
                    }
                }
                cnt++;
            }
        }
        if(!jud){
            ll mx=b.count();
            ans=max(ans,mx);
        }
    }
    cout<<ans<<endl;
}







































