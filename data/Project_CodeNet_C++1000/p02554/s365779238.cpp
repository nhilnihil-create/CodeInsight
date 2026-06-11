#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll)1e9+7;
ll n;

int main(){
    cin >> n;
    if(n==1) cout << 0;
    else if(n==2) cout << 2;
    else{
        ll t=1LL; ll e=1LL; ll ni=1LL;
        for(int i=0; i<n; i++){
            e*=8; e%=mod;
            ni*=9; ni%=mod;
            t*=10; t%=mod;
        }
        t-=ni; t-=ni; t+=e; t%=mod; t+=mod; t%=mod; cout << t;
    }
}
