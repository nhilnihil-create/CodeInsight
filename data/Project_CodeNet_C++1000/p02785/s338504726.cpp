#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll ans  = 0;
    for(int i = 0; i < n - k; i++) ans += a[i];
    cout << ans;

    return 0;
}
