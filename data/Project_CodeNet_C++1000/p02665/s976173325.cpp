#include <bits/stdc++.h>
#include <math.h>


    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846
    const int MOD=1e9+7;

    void solve(){
        int n;
        cin>>n;
        vector<ll>leaf(n+1);
        for(int i=0;i<=n;i++)
            cin>>leaf[i];
        if(leaf[0]>=2){
            cout<<-1;
            return;
        }
        vector<ll>sum(n+2);
        for(int i=1;i<=n+1;i++)
            sum[i]=sum[i-1]+leaf[i-1];
        vector<ll>n_leaf(n+1);
        n_leaf[0]=1-leaf[0];
        for(int i=1;i<=n;i++){
            n_leaf[i]=(2LL*n_leaf[i-1]) - leaf[i];
            n_leaf[i]=min(n_leaf[i],sum[n+1]-sum[i+1]);
            if(n_leaf[i]<0){
                cout<<-1;
                return;
            }
        }
//        for(int i=0;i<=n;i++)
//            cout<<sum[i]<<" ";
//        cout<<"\n";
//        for(int i=0;i<=n;i++)
//            cout<<n_leaf[i]<<" ";
//        cout<<"\n";
        ll ans=0;
        for(int i=0;i<=n;i++)
            ans+=leaf[i]+n_leaf[i];
        cout<<ans;
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
