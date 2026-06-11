#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846

    void solve(){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        ll total=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=lower_bound(a.begin(),a.end(),a[i]+a[j])-a.begin();
                total+=max(0,l-k);
            }
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
