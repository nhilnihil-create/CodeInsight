#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
#define MOD (int) 1e9+7
#define inf (int) (1e18)

void solve(){
    ll a,b,h,m;
    cin>>a>>b>>h>>m;
    long double cs=2.0 * atan(1)*4.0 * (h / 12.0 + m / 720.0 - m / 60.0);
    long double len=sqrt((a*a)+(b*b)-(2*a*b*cos(cs)));
    cout << setprecision(16) << len << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin >> t;
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}