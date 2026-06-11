//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> Hs(N);
    rep(i,0,N) {
        cin >> Hs[i];
    }
    set<ll> vals_set;
    vals_set.insert(0);
    rep(i,0,N) {
        vals_set.insert(Hs[i]);
    }
    vector<ll> vals;
    for (ll val : vals_set) {
        vals.push_back(val);
    }
    unordered_map<ll, ll> vals_idx;
    rep(i,0,vals.size()) {
        vals_idx[vals[i]] = i;
    }
    auto dp = make_vec_nd(numeric_limits<ll>::max(), N, K+1, vals.size());
    auto dp0 = make_vec_nd(numeric_limits<ll>::max(), N, K+1, vals.size()+1);
    auto dp1 = make_vec_nd(numeric_limits<ll>::max(), N, K+1, vals.size()+1);
    rep(k,0,K+1) {
        if (k >= 2) {
            break;
        }
        rep(val_idx,0,vals.size()) {
            ll val = vals[val_idx];
            if (val == Hs[0]) {
                if (k == 0) {
                    dp[0][k][val_idx] = val;
                }
            } else {
                if (k == 1) {
                    dp[0][k][val_idx] = val;
                }
            }
        }
    }
    rep(i,1,N) {
        rep(k,0,K+1) {
            rep(val_idx,1,vals.size()+1) {
                if (dp[i-1][k][val_idx-1] == numeric_limits<ll>::max()) {
                    dp0[i-1][k][val_idx] = dp0[i-1][k][val_idx-1];
                } else {
                    dp0[i-1][k][val_idx] = min(dp0[i-1][k][val_idx-1], dp[i-1][k][val_idx-1] - vals[val_idx-1]);
                }
            }
            rrep(val_idx,vals.size(),0) {
                dp1[i-1][k][val_idx] = min(dp1[i-1][k][val_idx+1], dp[i-1][k][val_idx]);
            }
        }
        rep(k,0,K+1) {
            rep(val_idx,0,vals.size()) {
                ll val = vals[val_idx];
                if (Hs[i] != val && k == 0) {
                    continue;
                }
                ll ref_k = (Hs[i] == val) ? k : (k-1);
                if (dp0[i-1][ref_k][val_idx] == numeric_limits<ll>::max()) {
                    dp[i][k][val_idx] = numeric_limits<ll>::max();
                } else {
                    dp[i][k][val_idx] = val + dp0[i-1][ref_k][val_idx];
                }
                dp[i][k][val_idx] = min(dp[i][k][val_idx], dp1[i-1][ref_k][val_idx]);
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    rep(k,0,K+1) {
        rep(val_idx,0,vals.size()) {
            ans = min(ans, dp[N-1][k][val_idx]);
        }
    }
    cout << ans << endl;
}

