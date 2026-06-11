#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
#define DEBUG

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int oo = 1e9 + 7;
const ll mod = 998244353, maxn = 200200;
const double PI = acos(-1);

bool check(ll n, ll d){
    while(n%d == 0) n/=d;
    return n%d == 1;
}

int main (){
    ll n;

    cin >> n;

    set<ll> ans;
    ans.insert(n);
    if (n != 2) ans.insert(n-1);
    for (ll i=2; i*i<=n; i++){
        ll d, nn = n-1;
        if (n%i == 0){
            d = n/i;
            if (check(n, d)) ans.insert(d);
            if (check(n, i)) ans.insert(i);
        }
        else if (nn % i == 0){
            d = nn/i;
            ans.insert(d);
            ans.insert(i);
        }
    }

    cout << ans.size() << endl;
    return 0;
}