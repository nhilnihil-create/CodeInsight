#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;


ll ans = 0;

int main(){
    AC
    ll a, b, n;
    cin>>a>>b>>n;
    ll x = min(b-1, n);
    ans = max(ans, (ll)floor((double)(a*x)/b));

    x = min(n, 2*b-1);
    ll test = floor((double)(a*x)/b) - a*(x/b);
    ans = max(ans, test);

    cout<<ans<<endl;

}