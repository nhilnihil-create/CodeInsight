#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.rbegin(),h.rend());
    ll ans = 0;
    if(n <= k){
        ans = 0;
    }
    else{
        for(int i=n-1; i>=k; i--){
            ans += h[i];
        }
    }
    cout << ans << endl;
    return 0;
}