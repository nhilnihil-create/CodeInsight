#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int n, a[N], b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);
    if(n & 1) {
        cout << b[n/2]-a[n/2]+1;
    }
    else {
        pair<ll, ll> le = {a[n/2 - 1], b[n/2]};
        pair<ll, ll> re = {a[n/2], b[n/2 - 1]};
        cout << (le.second+re.second)-(le.first+re.first)+1;
    }
    return 0;
}