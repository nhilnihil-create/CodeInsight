#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<ll> phi(maxn);
void gen()
{
    for(int i = 1; i < maxn; i++)
        phi[i] = i;
    for(int j = 2; j < maxn; j++){
        if(phi[j] == j){
            for(int k = j; k < maxn; k += j)
                phi[k] -= phi[k] / j;
        }
    }

}
ll power(ll a, ll p){
    if(p == 0) return 1;
    if(p == 1) return a % mod;
    if(p & 1) return a * power(a, p - 1) % mod;
    ll r = power(a, p / 2);
    return r * r % mod;
}
void add(ll &a, ll b){
    a += b;
    if(a > mod)
        a -= mod;
}
void check()
{
    int cnt = 0;
    int cnt2 = 0;
    set<pair<int, pair<int, int> > > s;
    for(int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                if(s.find(make_pair(i, make_pair(j, k))) != s.end()) continue;
                s.insert(make_pair(i, make_pair(j, k)));
                int gcd = __gcd(i, __gcd(j, k));
                if(i % 3 == 0 && j % 3 == 0 && k % 3 == 0) cnt2++;
                cout << i << ' ' << j << ' ' << k << " -> " << gcd << '\n';
                if(gcd == 3) cnt++;
            }
        }
    }
    cout << cnt << ' ' << cnt2 << '\n';
}

int main() {
//    check();
//    gen();
    IO;
    int n, k;
    cin >> n >> k;
//    phi[1] = 0;
//    for(int i = 1; i <= k; i++)
//        add(phi[i], phi[i - 1]);

    vector<ll> seq(k + 1);
    for(int i = 1; i <= k; i++)
        seq[i] = power(k / i, n);

    for(int i = k; i >= 1; i--){
        for(int j = i + i; j <= k; j += i)
            add(seq[i], -seq[j]);
    }

//    for(int i = 0; i <= k; i++)
//        cout << "seq[" << i << "] = " << seq[i] << '\n';
    ll ans = 0;
    for(int i = 1; i <= k; i++)
        add(ans, seq[i] * i % mod);

    cout << ans << '\n';
    return 0;
}
