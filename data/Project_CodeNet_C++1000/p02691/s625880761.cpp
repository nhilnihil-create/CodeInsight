
#include <bits/stdc++.h>
#include <math.h>


    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846
    const int MOD=1e9+7;

    void solve(){
        int n;
        cin>>n;
        ll k;
        vector<ll>a(n) , b(n);
        for(int i=0;i<n;i++){
            cin>>k;
            a[i]=i-k;
            b[i]=i+k;
        }
        sort(b.begin(),b.end());
        ll total=0;
//        for(int i=0;i<n;i++)
//            cout<<a[i]<<" ";
//        cout<<"\n";
//        for(int i=0;i<n;i++)
//            cout<<b[i]<<" ";
//        cout<<"\n";
        for(int i=0;i<n;i++){
            ll x=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            ll y=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            --y;
//            cout<<x<<" "<<y<<"\n";
            if(x<n && b[x]==a[i] && y<n && b[y])
                total+=(y-x+1);
        }
        cout<<total;
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
