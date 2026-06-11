#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = a[n-1];
    for (int i = 0; i < (n-2) / 2; ++i) {
        res += a[n-2-i] * 2;
    }
    if (n % 2) res += a[n-2-(n-2)/2];
    cout << res << endl;
}