#include <bits/stdc++.h>
#define rep(i, n)   for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i, n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll ans=0;
    ans += a[0];
    for(int i=1;i<=(n-1)/2;i++){
        ans += a[i]*2;
    }
    if(n%2==1) ans -= a[n/2];
    cout << ans << endl;
}
