#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll oo = 1e18;
const ll mod = 998244353,maxn = 3030;
const double PI = acos(-1);


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, less = 0, sum = 0;
    cin >> n >> m;

    vector<int> v(n);

    for (auto &x: v) cin >> x, sum += x;
    less = sum/(4*m);
    if (sum%(4*m)) less++;
    int cnt = 0;

    for (int i=0; i<n; i++){
        if (v[i] >= less) cnt++;
    }

    if (cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}