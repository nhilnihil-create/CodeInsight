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
    int n; cin >> n;
    vector<LL> a(n);
    for(auto &x: a) cin >> x;
    LL ans = 0;
    for(int bit = 0; bit < 60; ++bit) {
        LL cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < n; ++i) {
            if(((a[i]>>bit)&1) == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        (ans += cnt0*cnt1%MOD*((1LL<<bit)%MOD)%MOD)%=MOD;
    }
    cout << (ans + MOD) % MOD;
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