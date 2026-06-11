#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const ll INF = 1001001001001;
const int MOD = 1000000007;

int main(){
    ll A, B;
    cin >> A >> B;

    if (A > B) swap(A, B);

    vector<ll> v;
    for (int i = 1; (ll)i * i <= A; ++i) {
        if (A % i != 0) continue;
        if (B % i == 0) v.emplace_back(i);
        ll j = A / i;
        if (i != j && B % j == 0) v.emplace_back(j);
    }

    auto f = [&](ll x){
        if (x == 1) return true;
        for (int i = 2; (ll)i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    };

    int ans = 0;
    for (auto &i : v) {
        if (f(i)) ans++;
    }

    cout << ans << endl;
}