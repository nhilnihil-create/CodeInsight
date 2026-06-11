#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e18 + 7;
const ll mod = 1e9 + 7, maxn = 202;  
const long double PI = acos(-1);


int solve(string s, int n){
    int w = 0, r = 0, nw = 0, nr = 0, ans;
    for (int i=0; i<n; i++){
        if (s[i] == 'W') w++;
        else r++;
    }

    ans = min(r, w);
    for (int i=1; i<=n; i++){
        if (s[i-1] == 'W') nw++, w--;
        else nr++, r--;
        int cost = nw + r - min(nw, r);
        ans = min(ans, cost);
    }

    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    int ans = solve(s, n);

    cout << ans << endl;
    return 0;   
}