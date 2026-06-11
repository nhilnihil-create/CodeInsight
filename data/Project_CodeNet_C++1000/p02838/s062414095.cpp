#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#define dbg(x) cerr << "[" #x << " : " << x << "]\n"

const int mod = (int)1e9+7;

int main()
{
    int n;
    scanf("%d", &n);
    i64 a[400000];
    vector<int> cnt(65, 0);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for(i64 j = 0; j < 62; j++) {
            cnt[j] += ((a[i] & (1LL << j)) > 0);
        }
    }
    vector<i64> powers(65, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 62; j++) {
            if(a[i] & (1LL<<j)) {
                cnt[j]--;
                powers[j] += n-i-1-cnt[j];
            } else {
                powers[j] += cnt[j];
            }
        }
    }
    i64 ans = 0;
    for(int i = 0; i < 61; i++) {
        i64 tmp = powers[i];
        for(int j = 1; j <= i; j++) {
            tmp *= 2;
            tmp %= mod;
        }
        ans += tmp;
        ans %= mod;
    }
    printf("%lld\n", ans);
}
