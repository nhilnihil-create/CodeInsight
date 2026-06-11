#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];

    int ans=INF;

    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    rep(i,n){
        rep(j,n){
            if(i==j) continue;

            ll dx=x[j]-x[i],dy=y[j]-y[i];
            int sub=0;
            for(int i2=0;i2<n;i2++){
                for(int j2=0;j2<n;j2++){
                    if(i2==j2) continue;
                    if(dx==x[j2]-x[i2] && dy==y[j2]-y[i2]) sub++;
                }
            }
            ans=min(ans,n-sub);
        }
    }

    cout<<ans<<endl;
} 
