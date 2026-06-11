#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846

    void solve(){
        int n;
        cin>>n;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j+=i)
                a[j]++;
        }
        ll total=0;
        for(ll i=1;i<=n;i++)
            total+=(i*(ll)a[i]);
        cout<<total;
    }
    int main(){
        
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
