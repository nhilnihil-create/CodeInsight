#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main() {
    int n;
    cin >> n;
    int ans = n % 1000;
    ans = 1000 - ans;
    if(ans == 1000){
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}