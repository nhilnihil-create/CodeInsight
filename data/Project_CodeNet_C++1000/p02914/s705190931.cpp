// 解答不能.
// 以下のソースコードを勉強する.
// pekempey氏.
// https://atcoder.jp/contests/abc141/submissions/7548203
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

using namespace std;
using ll = long long;

int main(){
    int N;
    scanf("%d", &N);
    vector<ll> A(N); rep(i, N) scanf("%lld", &A[i]);
    ll ans = 0;
    rep(i, 60){
        int s = 0;
        rep(j, N) s ^= A[j] >> i & 1;
        if(s == 1){
            ans += 1LL << i;
            rep(j, N) A[j] &= ~(1LL << i);
        }
    }
    vector<ll> bases;
    sort(range(A), greater<>());
    for(ll x : A){
        for(ll y : bases) x = min(x, x ^ y);
        if(x != 0) bases.push_back(x);
    }
    ll s = 0;
    for(ll x : bases) s = max(s, s ^ x);
    printf("%lld\n", ans + s * 2);
    return 0;
}