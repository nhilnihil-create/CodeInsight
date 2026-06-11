#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
//#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e6 + 100;
const int oo = 1e8;
const int mod = 1e9 + 7;

int n;
int a[N];

int lucas(int k, int n)  {
    while(k > 0 || n > 0)   {
        int k1 = k % 2, n1 = n % 2;
        k /= 2; n /= 2;
        if(k1 > n1) return 0;
    }
    return 1;
}

int solve()    {
    int ans = 0;
    FOR(i, 1, n) ans = (ans + lucas(i - 1, n - 1) * a[i]) % 2;
    return ans;
}

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    scanf("%d", &n);

    bool flag = 0;
    FOR(i, 1, n){
        char x; scanf(" %c", &x);
        a[i] = x - '0';
        a[i] -= 1;
        if(a[i] == 1) flag = 1;
    }
    int tmp = solve();
    if(tmp) return cout << tmp, 0;
    if(flag) return cout << "0", 0;
    FOR(i, 1, n) a[i] /= 2;
    tmp = 2 * solve();
    return cout << tmp, 0;
}
