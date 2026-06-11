#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;


int main() {
    int n; cin >> n;
    int a[n]; rep(i,n) cin >> a[i];
    int ans = 0, cnt = 0;
    rep(i,n-1) {
        if (a[i] >= a[i+1]) {
            cnt++;
        } else {
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    cout << max(ans, cnt) << endl;
    return 0;
}
