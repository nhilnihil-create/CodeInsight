#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int) 1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = [", __print(x)
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)

i64 C[2002][2002];
int main()
{
    memset(C, 0, sizeof C);
    for(int i = 0; i <= 2000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
                C[i][j] %= mod;
            }
        }
    }
    i64 n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= k; i++) {
        i64 ans = 0;
        if(n == k) {
            if(i == 1) puts("1");
            else puts("0");
            continue;
        }
        if(i > 1)
            ans += C[k-1][i-1]*C[n-k-1][i-2];
        ans %= mod;
        ans += C[k-1][i-1]*C[n-k-1][i];
        ans %= mod;
        ans += 2*C[k-1][i-1]*C[n-k-1][i-1];
        ans %= mod;
        printf("%lld\n", ans);
    }
}
