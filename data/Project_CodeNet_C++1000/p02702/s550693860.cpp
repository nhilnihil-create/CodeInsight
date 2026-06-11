#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define mod ll(2019)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    string s;
    cin >> s;

    ll n = s.size();
    vector<ll> v(mod, 0LL);
    v[0] = 1;
    ll coef = 1;
    ll num = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll tmpnum = s[n-1-i]-'0';
        num += coef*tmpnum;
        num %= mod;
        coef *= 10;
        coef %= mod;
        v[num]++;
    }
    for(int i = 0; i < mod; i++){
        ans += v[i]*(v[i]-1)/2;
    }
    cout << ans << endl;
}
