#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); ++i)
#define all(x) x.begin(),x.end()
typedef long long int ll;

int main(){
    ll n; cin >> n;
    ll vertex=0, side =0, ans=0;
    vector<ll> u(n-1),v(n-1); 
    rep(i,n-1){
        cin >> u[i] >> v[i];
        if (u[i]<v[i]) side+=u[i]*(n-v[i]+1);
        else side+= v[i]*(n-u[i]+1);
    } 
    rep(i,n) vertex+=(i+1)*(n-i);
    ans = vertex - side;
    cout << ans << endl;
    return 0;
}