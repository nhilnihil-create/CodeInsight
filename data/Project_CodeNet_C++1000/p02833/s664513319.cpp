#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846

    void solve(){
        ll n;
        cin>>n;
        if(n%2)
            cout<<0;
        else{
            long long total=0;
            long long num=10;
            while(n>=num){
                total+=(n/num);
                num*=5LL;
            }
            cout<<total;
        }
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
