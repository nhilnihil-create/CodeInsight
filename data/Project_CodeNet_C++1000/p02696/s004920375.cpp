#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i,n) for (long long i=0; i<(long long)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    ll a,b,n;
    cin>>a>>b>>n;
    if(n<b){
        ll x=n;
        ll ans=ll(a*n/b)-a*ll(n/b);
        cout<<ans<<endl;
        return 0;
    }
    else if(n>=b){
        ll x=b-1;
        ll ans=ll(a*x/b)-a*ll(x/b);
        cout<<ans<<endl;
        return 0;
    }
}