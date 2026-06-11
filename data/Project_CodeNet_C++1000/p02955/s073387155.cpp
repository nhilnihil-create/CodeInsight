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

vector<ll> enum_divisors(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0){
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    auto div = enum_divisors(sum);
    sort(rall(div));
    for (auto d : div) {
        vector<int> rem(n);
        for (int i = 0; i < n; ++i) {
            rem[i] = a[i] % d;
        }
        sort(all(rem));
        vector<int> minus(n+1, 0);
        vector<int> plus(n+1, 0);
        for (int i = 0; i < n; ++i) {
            minus[i+1] += minus[i] + rem[i];
            plus[i+1] += plus[i] + (d - rem[i]);
        }
        for (int i = 0; i <= n; ++i) {
            if (minus[i] == plus[n] - plus[i] && minus[i] <= k) {
                cout << d << endl;
                return 0;
            }
        }
    }
}