#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    ll n;
    cin >> n;
    string ans;
    while (n > 0) {
      n--;
      ans += 'a' + n%26;
      n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}