#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    LL n, k, q;
    cin >> n >> k >> q;
    vector<LL> a(n+1);
    for(int i = 0; i < q; ++i) {
        int x; cin >> x;
        a[x]++;
    }
    for(int i = 1; i <= n; ++i) cout << (k-q+a[i] > 0?"Yes":"No") << "\n";
    
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
