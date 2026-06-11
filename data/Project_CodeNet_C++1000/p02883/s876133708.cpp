#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()

vector<i64> a, f;

int main(){
    i64 n, k;
    cin >> n >> k;
    a.resize(n); f.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(all(a), greater<i64>());
    sort(all(f));
    i64 ng = 1e18 + 100, ok = -1;
    while(abs(ok - ng) > 1){
        i64 mid = (ok + ng) / 2;
        i64 sum = 0;
        rep(i, n){
            i64 lim = mid / f[i];
            sum += max(0LL, a[i] - lim);
        }
        if(sum <= k) ng = mid;
        else ok = mid;
    }
    cout << ok + 1 << endl;
}