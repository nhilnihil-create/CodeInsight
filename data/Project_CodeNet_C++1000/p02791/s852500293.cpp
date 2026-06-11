#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> m(n);
    m[0] = p[0];
    rrep(i,n-1) m[i] = min(m[i-1], p[i]);
    int ans = 0;
    rep(i,n) if(m[i] == p[i]) ans++;
    cout << ans << endl;

    return 0;
}
