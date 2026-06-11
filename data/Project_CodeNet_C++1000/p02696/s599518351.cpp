#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    ll a, b, n;
    cin>>a>>b>>n;
    ll x = b-1;
    if(x > n)
        x = n;
    ll ans = a*x;
    ans /= b;
    ans -= a*(x/b);
    cout<<ans<<endl;
    return 0;
}