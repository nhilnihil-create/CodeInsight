#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

void solve() {
    int n, d; cin >> n >> d;
    cout << (n + 2*d)/(2*d+1);
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}