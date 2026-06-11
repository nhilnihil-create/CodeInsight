#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> id(n+1, -1);
    vector<int> s;
    int len = 0;
    int x = 1;
    while (id[x] == -1) {
        id[x] = len;
        s.push_back(x);
        len++;
        x = a[x];
    }

    int c = len - id[x];

    int ans = 0;
    if (k < len) {
        ans = s[k];
    }
    else {
        k -= len;
        k %= c;
        ans = s[id[x]+k];
    }
    cout << ans << endl;
    return 0;
}