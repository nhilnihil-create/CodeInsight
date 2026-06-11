#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

const int MAX_N = 200010;
int n;
ll k;
vector<ll> A;
vector<ll> F;

int main() {
    cin >> n >> k;
    rp(i, 0, n) {
        ll a; scanf("%lld", &a);
        A.emplace_back(a);
    }
    rp(i, 0, n) {
        ll f; scanf("%lld", &f);
        F.emplace_back(f);
    }
    sort(F.begin(), F.end());
    sort(A.rbegin(), A.rend());
    ll ng = -1ll; ll ok = 1ll<<50;
    while(llabs(ok-ng) > 1) {
        ll x = (ng+ok)/2;
        ll m = 0;
        rp(i, 0, n) {
            ll req = x / F[i];
            if(A[i] > req) m += (A[i] - req);
        }
        if(m <= k) ok = x;
        else ng = x;
    }
    cout << ok << endl;
    return 0;
}