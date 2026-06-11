#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    LL n; cin >> n;
    LL x = n+1, y = n+1;
    for(LL i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            LL nx = i, ny = n / i;
            if(nx + ny < x + y) x = nx, y = ny;
        }
    }
    cout << (x+y-2);
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
