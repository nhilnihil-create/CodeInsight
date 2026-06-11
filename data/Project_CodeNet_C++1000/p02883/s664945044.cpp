#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, k;

int main() {
    cin >> n >> k;
    vector<ll> A(n, 0);
    for(int i = 0; i < n; ++i) cin >> A.at(i);
    vector<ll> F(n, 0);
    for(int i = 0; i < n; ++i) cin >> F.at(i);
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());

    ll ng = -1, ok = 1e12;
    while(abs(ok-ng) > 1) {
        ll mid = (ok+ng) / 2;
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += max(0ll, A.at(i) - mid/F.at(i));
        }
        if(sum <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}