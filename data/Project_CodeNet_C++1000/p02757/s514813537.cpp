#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
// #define DEBUG 10

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = 500050;
const double PI = acos(-1);

vector<int> p(maxn, 0);
void init(int n){
    for (int i=0; i<=n; i++){
        p[i] = i;
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    ll n, p, ans = 0, atual = 0, pot = 1;
    string s;
    cin >> n >> p;
    cin >> s;
    // n = s.size();

    vector<ll> rest(p + 1, 0);
    rest[0] = 1;

    if (__gcd(10LL, p) == 1){
        for (ll i=n-1; i>=0; i--){
            ll dig = (s[i] - '0');
            atual = (dig*pot + atual)%p;
            ans += rest[atual];
            rest[atual]++;
            pot = (pot*10)%p;
        }

        cout << ans << endl;
    }
    else {
        for (int i=n-1; i>=0; i--){
            ll dig = s[i] - '0';
            if (dig%p == 0) ans+=i+1;
        }
        cout << ans << endl;
    }
    return 0;
}