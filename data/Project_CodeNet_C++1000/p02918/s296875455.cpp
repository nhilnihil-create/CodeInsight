#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    int ans = n;
    if(s[0] == 'L') ans--;
    if(s[n-1] == 'R') ans--;
    rep(i, n - 1){
        if(s[i] == 'R' && s[i + 1] == 'L') ans-=2;
    }
    ans += 2 * k;
    if(ans >= n - 1) ans = n - 1;
    cout << ans << endl;
    return 0;
}