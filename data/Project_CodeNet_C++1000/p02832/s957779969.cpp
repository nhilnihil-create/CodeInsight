#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt == a[i]) cnt++;
        else ans++;
    }
    if(ans == n) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
