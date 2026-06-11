#include <bits/stdc++.h>
#define pb push_back
#define pii pair<ll, ll>
#define nyan "(=^･ω･^=)"
#define read_input         freopen("in.txt","r", stdin)
#define print_output       freopen("out.txt","w", stdout)
typedef long long ll;
typedef long double ld;
using namespace std;

const ll maxn = 4e3+10;
ll pre[4][maxn], a[maxn];

ll other(ll a, ll b) {
    if(a > b) swap(a, b);
    if(a == 1 && b == 2) return 3;
    if(a == 1 && b == 3) return 2;
    if(a == 2 && b == 3) return 1;
}

int main() 
{
    ll n; string s;
    cin >> n >> s;

    for(ll i = 1; i <= n; i++) {
        if(s[i-1] == 'R') pre[1][i]++, a[i] = 1;
        if(s[i-1] == 'G') pre[2][i]++, a[i] = 2;
        if(s[i-1] == 'B') pre[3][i]++, a[i] = 3;
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= 3; j++)
            pre[j][i] += pre[j][i-1];
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = i+1; j <= n; j++) {
            if(a[i] == a[j]) continue;

            ll c = other(a[i], a[j]);

            ans += pre[c][i-1];
            if(2*i-j >= 1 && 2*i-j <= n) ans -= a[2*i-j] == c;
        }
    }

    cout << ans << endl;

    return 0;  
}