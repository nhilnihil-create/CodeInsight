/* Author: Rennan Rocha
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

ll bruto(ll x) {
    ll cnt = 0;
    for(ll i = 2; i <= x; i++) {
        ll aux = x;
        while(aux >= i) {
            if(aux%i==0) aux /= i;
            else aux -= i;
        }
        if(aux == 1) cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll n_ini = n;
    n--;
    ll ans = 1;
    for(ll i = 2; i * i <= n; i++) {
        ll cnt = 1;
        while(n%i==0) {
            cnt++;
            n/=i;
        }
        ans *= cnt;
    }
    if(n > 1){ 
        ans *= 2;
    }

    vll divs;
    for(ll i = 2; i * i <= n_ini; i++) {
        if(n_ini % i == 0) {
            divs.PB(i);
            if(n_ini/i != i) divs.PB(n_ini/i);
        }
    }
    for(ll d : divs) {
        ll aux = n_ini;
        while(aux%d==0) aux /= d;
        if(aux%d==1) ans++;
    }

    cout << ans << "\n";
}
