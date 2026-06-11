#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    ll n; cin>>n;
    if(n&1) return cout<<"0\n", 0;

    ll ans = 0, den = 10, t;
    while(den <= n){
        ans += n/den;
        den *= 5;
    }
    cout<<ans<<"\n";
    return 0;
}