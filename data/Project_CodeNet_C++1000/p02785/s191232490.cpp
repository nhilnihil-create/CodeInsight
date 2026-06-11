#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
 
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
 
    ll ans(0);
    rep(i,n-k){
        ans += v[i];
    }
 
    cout << ans << endl;
 
    return 0;
}