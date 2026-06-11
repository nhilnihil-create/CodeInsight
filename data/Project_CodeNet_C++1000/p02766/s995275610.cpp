#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > 0) {
        ans++;
        n /= k;
    }
    cout << ans << endl;
    return 0;
}