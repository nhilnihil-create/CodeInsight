#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    rep(i,N) cin >> X[i];
    ll ans = 100100100;
    rep(p,101){
        ll tot = 0;
        rep(i,N){
            tot += pow(X[i]-p,2);
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;
    return 0;
}