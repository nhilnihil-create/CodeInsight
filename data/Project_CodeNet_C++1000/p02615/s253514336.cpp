#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.rbegin(),a.rend());
    int t = n-1;
    ll ans = 0;
    rep(i,n){
        int lim = 2;
        if(i == 0) lim = 1;
        rep(j,lim){
            if(t > 0){
                ans += a[i];
                t--;
            }
        }
    }
    cout << ans << endl;
}