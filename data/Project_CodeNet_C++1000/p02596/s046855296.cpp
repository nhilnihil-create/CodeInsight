#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = (1 * 1e5) + 10;
const long double PI = acos(-1);

int solve (ll k){
    ll val = 7%k;

    for (int i=1; i<=k+1; i++){
        if (val == 0) return i;
        val = (val*10 + 7) % k;
    }
    return -1;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;

    int ans = solve(k);

    cout << ans << endl;
    return 0;
}