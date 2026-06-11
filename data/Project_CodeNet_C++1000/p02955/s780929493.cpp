#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(o) (o).begin(), (o).end()
using namespace std;
typedef int_fast64_t ll;

size_t i, j;
ll N, K, S = 0;
ll cnt, buff, tmp;
ll A[500], B[500];
ll x, y;
vector<ll> cand;

inline bool solve(ll m) {
    for(i = 0; i < N; i++) B[i] = A[i] % m;
    sort(B, B + N);
    cnt = 0, buff = 0, tmp;
    for(i = 0, j = N - 1; i <= j; i++) {
        if(B[i] == 0 || B[i] == m) continue;
        buff = B[i];
        cnt += B[i];
        B[i] = 0;
        if(cnt > K) return false;
        while(buff && j >= i) {
            if(B[j] == 0 || B[j] == m) {
                j--;
                continue;
            }
            tmp = m - B[j];
            if(tmp > buff) {
                B[j] += buff;
                break;
            } else {
                buff -= tmp;
                j--;
            }
        }
    } 
    return true;
}

int main() {
    scanf("%lld %lld", &N, &K);
    REP(i, N) {
        scanf("%lld", A + i);
        S += A[i];
    }
    x = 1, y;
    while(x * x <= S) {
        if(S % x == 0) {
            y = S / x;
            if(solve(y)) {
                printf("%lld\n", y);
                return 0;
            }
            cand.push_back(x);
        }
        x++;
    }
    reverse(ALL(cand));
    for(auto& c : cand) if(solve(c)) {
        printf("%lld\n", c);
        break;
    }
	return 0;
}