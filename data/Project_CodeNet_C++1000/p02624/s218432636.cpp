#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll now = n / i;
        ans += ((i + now * i) * now) / 2;
    }
    cout << ans;
    return 0;
}
