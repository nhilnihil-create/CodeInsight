#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    LL a, b;
    cin >> a >> b;
    LL gcd = __gcd(a, b);
    int ans = 1;
    for(LL i = 2; i*i <= gcd; ++i) {
        if(gcd % i == 0) {
            ans++;
            while(gcd % i == 0) gcd /= i;
        }
    }
    if(gcd > 1) ans++;
    cout << ans;
}


int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}