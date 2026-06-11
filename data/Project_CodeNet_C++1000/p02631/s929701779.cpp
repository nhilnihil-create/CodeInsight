#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res ^= a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == n-1) cout << (res ^ a[i]) << endl;
        else cout << (res ^ a[i]) << " ";
    }
}