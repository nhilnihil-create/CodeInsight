#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846

    void solve(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int total=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1])
                total++;
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
