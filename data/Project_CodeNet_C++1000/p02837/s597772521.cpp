#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int n; cin >> n;
    vector<int> a(n+1);
    vector<pii> b[n+1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        for(int j = 0; j < a[i]; ++j) {
            int x, y;
            cin >> x >> y;
            b[i].emplace_back(x, y);
        }
    } 
    int ans = 0;
    for(int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        bool flag = true;
        for(int j = 0; j < n && flag; ++j) {
            if((i >> j) & 1) {
                cnt++;
                for(int k = 0; k < a[j+1] && flag; ++k) {
                    if(((i >> (b[j+1][k].first-1) & 1 )!= b[j+1][k].second)) flag = false;
                }
            }
        }
        if(flag) ans = max(ans, cnt);
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