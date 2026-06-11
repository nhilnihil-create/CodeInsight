#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, R;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> R;
    if (N>=10) cout << R << endl;
    else cout << R+100*(10-N) << endl;
}