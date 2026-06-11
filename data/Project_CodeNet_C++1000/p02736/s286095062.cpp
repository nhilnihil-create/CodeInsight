#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define mem(i, j) memset(i, j, sizeof(i))
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define dep(i, j, k) for(int i = k; i >= j; i--)
#define pb push_back
#define make make_pair
#define INF INT_MAX
#define inf LLONG_MAX
#define PI acos(-1)
using namespace std;

const int N = 1e6 + 5;

const LL mod = 1e9 + 7;

LL ksm(LL a, LL b) { LL ans = 1LL; while(b) { if(b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1; }  return ans; }

char a[N];
int fac[N];

void init(int n) {
    fac[0] = 0;
    rep(i, 1, n) {
        fac[i] = fac[i - 1];
        int tmp = i;
        while(tmp % 2 == 0) {
            fac[i]++;
            tmp = tmp / 2;
        }
    }
}

int C(int n, int m) {
    return fac[n] - fac[m] - fac[n - m];
}

void solve() {

    int n;

    scanf("%d", &n);

    scanf("%s", a + 1);

    bool flag0 = 0, flag1 = 0, flag2 = 0;

    rep(i, 1, n) {
        a[i]--;
        if(a[i] == '0') flag0 = 1;
        if(a[i] == '1') flag1 = 1;
        if(a[i] == '2') flag2 = 1;
    }
    if(flag0 + flag1 + flag2 <= 1) {
        puts("0"); return ;
    }

    init(n);

    int ans = 0;
    if(flag1) {
        rep(i, 1, n) {
            if(a[i] == '1') {
                if(C(n - 1, i - 1) == 0) ans ^= 1;
            }
        }
    }
    else {
        rep(i, 1, n) {
            if(a[i] == '2') {
                if(C(n - 1, i - 1) == 0) ans ^= 1;
            }
        }
        ans = ans * 2;
    }
    printf("%d\n", ans);
}


int main() {
//    int _; scanf("%d", &_);
//    while(_--) solve();
//
    solve();

    return 0;
}
