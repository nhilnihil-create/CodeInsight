#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int ans = 0;
    rep(i,n) {
        rep(j,i) ans += d[i] * d[j];
    }
    cout << ans << endl;

    return 0;
}
