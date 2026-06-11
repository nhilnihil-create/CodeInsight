#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    int b[n-1]; rep(i,n-1) cin >> b[i];
    int s = b[0];
    rep(i,n-2) {
        s += min(b[i],b[i+1]);
    }
    cout << s+b[n-2] << endl;
    return 0;
}
