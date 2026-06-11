#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const LL MOD = 1e9+7;

void run_case() {
    int n, k;
    cin >> n >> k;
    LL ans = 0;
    for(int i = k; i <= n+1; ++i) {
        LL t1 = 1LL*(i-1)*i/2;
        LL t2 = 1LL*(n+n-i+1)*i/2;
        (ans += t2 - t1 + 1) %= MOD;
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}