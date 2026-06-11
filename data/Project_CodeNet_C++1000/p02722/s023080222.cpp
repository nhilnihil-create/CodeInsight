#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    set<ll> ans;
    for(ll k = 2; k * k <= n; k++){
        if(n % k == 0){
            ll m = n;
            while(m % k == 0)m /= k;
            if(m % k == 1)ans.insert(k);
            ll l = n;
            if(m == 1)continue;
            while(l % m == 0)l /= m;
            if(l % m == 1)ans.insert(m);
        }
    }
    ll m = n - 1;
    for(ll k = 2; k * k <= n; k++){
        if(m % k == 0){
            if(n % k != 0)ans.insert(k);
            if(n % (m / k) != 0)ans.insert(m/k);
        }
    }
    if(n>2)ans.insert(n-1);
    ans.insert(n);
    cout << ans.size() << endl;
}