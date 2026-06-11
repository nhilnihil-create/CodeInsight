#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

inline LL _lcm(LL a, LL b) {
    return a*b/__gcd(a,b);
}

void run_case() {
    int n; LL m;
    cin >> n >> m;
    vector<LL> a(n);
    for(auto &x: a) cin >> x, x >>= 1;
    LL lcm = a[0];
    for(int i = 1; i < n; ++i)
        lcm = _lcm(lcm, a[i]);
    for(int i = 0; i < n; ++i)
        if((lcm/a[i]) % 2 == 0) {
            cout << 0;
            return;
        }
    cout << (m/lcm+1)/2;
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