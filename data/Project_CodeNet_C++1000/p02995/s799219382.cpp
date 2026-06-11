#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll a, b, c, d;
ll findans(ll num){
    ll cnt = std::lcm(c, d);
    ll ans = num/cnt*(cnt+1-(cnt/c)-(cnt/d));
    ll res = num%cnt;
    ans += res - (res/c + res/d);
    return ans;
}



int main() {
    cin >> a >> b >> c >> d;
    ll ans = findans(b) - findans(a-1);
    cout << ans << endl;
}