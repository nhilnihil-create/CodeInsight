#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int a[100001];
ll l[100002];
ll r[100002];

int main() {
    int n, i;
    ll x = 1, ans = 0;
    cin >> n; 
    for (i = 0; i <= n; i++) cin >> a[i];
    l[n] = r[n] = a[n];
    for (i = n - 1; i >= 0; i--) {
        l[i] = a[i] + (l[i + 1] + 1) / 2;
        r[i] = a[i] + r[i + 1];
    }
    for (i = 0; i <= n; i++) {
        if (l[i] > x) {
            cout << -1 << "\n";
            return 0;
        }
        if (x > r[i]) x = r[i];
        ans += x;
        x = min((x - a[i]) * 2, r[i + 1]);
    }
    
    cout << ans << "\n";
    return 0;
}