#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const double PI = acos(-1);

ll f(ll n){
    while (n > 9){
        n/=10;
    }
    return n;
}

int main (){
    int n;
    cin >> n;

    vector<vector<ll>> a(10, vector<ll> (10, 0)), b(10, vector<ll> (10, 0));

    for (int i=1; i<=n; i++){
        ll last = i%10, first = f(i);
        if (last != 0){
            a[first][last]++;
            b[last][first]++;
        }
    }

    ll ans = 0;
    for(int i=1; i<10; i++){
        for (int j=1; j<10; j++){
            ans += (a[i][j])*(b[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}