#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    int ans= 0;
    rep(i, n){
        ans += i;
    }
    cout << ans << endl;;
    return 0;
}