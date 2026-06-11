#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 300006;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    map<ll,ll> h;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        h[i - a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        h[i - a[i]]--;
        ans += h[i + a[i]];
    }
    cout << ans << '\n';
    return 0; 
}
 