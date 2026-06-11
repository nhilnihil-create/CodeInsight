#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n-1) cin >> b[i];
    int ans = b[0]+b[n-2];
    rep(i,n-2) {
        ans += min(b[i],b[i+1]);
    }
    cout << ans << endl;

    return 0;
}
