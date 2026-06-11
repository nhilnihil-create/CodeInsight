#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] /= 2;
    }

    ll lcm = 1;
    for (int i = 0; i < n; ++i) {
        lcm = lcm / gcd(lcm, a[i]) * a[i];
        if (lcm > m){
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if ((lcm / a[i]) % 2 == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (m / lcm + 1) / 2 << endl;
}