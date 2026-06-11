#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }
    for(int i = 0; i < m; ++i) {
        int x = q.top();
        q.pop();
        q.push(x / 2);
    }
    LL ans = 0;
    while(!q.empty()) {
        ans += q.top();
        q.pop();
    }
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