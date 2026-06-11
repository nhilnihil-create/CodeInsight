#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll x;
    if(n>=b-1) x=b-1;
    else x=n;

    ll ans=(a*x)/b-a*(x/b);
    cout<<ans<<endl;
}