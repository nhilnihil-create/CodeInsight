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
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    function<int(int,int)> solve = [&](int i, int j) {
        int l = j, r = n-1, mid, ans;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(a[mid] < a[i]+a[j]) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans - j;
    };
    LL ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
            ans += solve(i, j);
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