#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> s(100010, -1);
const ll MOD = 1e9 + 7;

ll modStep(int n) {
    if (s[n] != -1) return s[n];
    if (n == 0) return s[0] = 1;
    if (n == 1) return s[1] = 1;
    else return s[n] = (modStep(n-2) + modStep(n-1)) % MOD;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(m);

    
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        s[a[i]] = 0;
    }

    ll ans = modStep(n);

    cout << ans << endl;
}