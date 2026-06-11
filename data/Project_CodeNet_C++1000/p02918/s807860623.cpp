#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]) cnt++;
    }

    int ans = min(cnt + 2 * k, n - 1);
    cout << ans << endl;
}
