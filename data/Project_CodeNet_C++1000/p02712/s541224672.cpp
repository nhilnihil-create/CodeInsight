#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    ll ans = 0;
    rep(i,N) if ((i+1) % 3 != 0 && (i+1) % 5 != 0) ans += (ll)i + 1;
    cout << ans << endl;
}
