#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

void solve() {
    vector<int> v{1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k; cin >> k;
    cout << v[k-1];

}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}