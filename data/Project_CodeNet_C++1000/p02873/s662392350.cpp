#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    int n = s.size();

    V<int> a(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == '<') a[i + 1] = max(a[i + 1], a[i] + 1);
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '>') a[i] = max(a[i], a[i + 1] + 1);
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}
