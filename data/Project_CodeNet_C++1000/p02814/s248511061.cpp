#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll x, n, m, res=1, ans;
set<ll>s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> x;
        x /= 2;
        if(s.find(x) == s.end()) {
            s.insert(x);
            res = res / __gcd(res, x) * x;
        }
    }

    for(auto x : s)
        if(res / x % 2 == 0) {
            cout << 0;
            return 0;
        }

    ans = m / res;
    ans = (ans+1) / 2;
    cout << ans;
}