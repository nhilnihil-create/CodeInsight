#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n, k;
    cin >> n >> k;

    vector<llint> a(n);
    vector<llint> f(n);
    for(llint in=0;in<n;++in) {
        cin >> a[in];
    }
    for(llint in=0;in<n;++in) {
        cin >> f[in];
    }
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<llint>());

    llint l=0, r = a[n-1]*f[0], mid, ans = a[n-1]*f[0], ktmp;
    while(l<r) {
        mid = l + (r - l) / 2;
        ktmp = 0;
        for(llint in=0;in<n;++in) {
          if(a[in]*f[in]<=mid) continue;
            ktmp += a[in] - mid / f[in];
        }
        if(ktmp<=k) {
            chmin(ans, mid);
            r = mid;
        }
        else l = mid + 1;
    }

    cout << ans << endl;
    return 0;
}
