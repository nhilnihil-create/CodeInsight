#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll N = 5e5 + 5;

string s;
ll ans;
ll a[N];

void solve() {
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '<') a[i + 1] = a[i] + 1; 
    }
    for(ll i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '>') 
            a[i] = max(a[i], a[i + 1] + 1);
    }
    ans = 0;
    for(ll i = 0; i <= s.size(); i++) {
        ans += a[i];
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}