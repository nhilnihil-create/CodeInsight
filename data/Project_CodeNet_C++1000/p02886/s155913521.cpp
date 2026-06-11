#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846

    void solve(){
        ll total=0;
        int d;
        cin>>d;
        vector<int>a(d);
        for(int i=0;i<d;i++)
            cin>>a[i];
        for(int i=0;i<d;i++){
            for(int j=i+1;j<d;j++)
                total+=(ll)a[i]*(ll)a[j];
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
