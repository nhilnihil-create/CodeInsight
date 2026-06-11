#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const int mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    rep(i,n)  cin >> a[i];
    
    ll ans = 0;
    rep(i,60) {
        ll cnt, sum;
        cnt = sum = 0;
        rep(j,n) {
            if(a[j]>>i & 1)
                cnt++;
        }
        sum += cnt * (n-cnt) % mod;
        rep(j,i) {
            sum = sum * 2 % mod;
        }
        ans = (ans + sum) % mod;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
