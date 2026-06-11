//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e15;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, ans, a[maxn], l[maxn], r[maxn];

bool check(ll x, ll d){
    while(x > 1){
        d--;
        x = (x + 1) >> 1;
    }
    return (d >= 0);
}

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i <= n; i++){
        cin >> a[i];
        r[i] = l[i] = a[i];;
    }
    for(ll i = n; i > 0; i--){
        l[i - 1] += (l[i] + 1) / 2;
        r[i - 1] += r[i];
        if(r[i] == 0 || !check(l[i], i)){
            cout << -1;
            return 0;
        }
    }
    if(l[0] > 1 || r[0] == 0){
        cout << -1;
        return 0;
    }
    r[0] = 1;
    for(ll i = 0; i <= n; i++){
        ans += r[i];
        r[i] -= a[i];
        r[i + 1] = min(r[i + 1], r[i] * 2);
    }
    cout << ans;

    return 0;
}
