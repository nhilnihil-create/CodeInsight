#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    int n;
    const ll max=1e18;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i]==0){
            cout << 0 << endl;
            return 0;
            }
    }
    ll ans=a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max/ans){
            cout << -1 << endl;
            return 0;
        }else{ 
            ans *= a[i];
            }
    }
    cout << ans << endl;
}