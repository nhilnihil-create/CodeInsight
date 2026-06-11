#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    ll N; cin >> N;
    ll ans = 0;
    if(N % 2 == 0) {
        ll baisuu = 5;
        while(N / baisuu != 0) {
            ans += (N / baisuu) / 2;
            baisuu *= 5;
        }
    }
    cout << ans << endl;
    return 0;
}
