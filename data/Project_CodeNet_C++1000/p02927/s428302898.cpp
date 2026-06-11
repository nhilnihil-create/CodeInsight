#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll m,d;
ll ans;

int main(){
    cin >> m >> d;
    for(ll i = 1;i <= m;i++){
        for(ll j = 10;j <= d;j++){
            ll d1 = (j%10);
            ll d10 = (j/10);
            if(d1*d10 == i && d1 >= 2 && d10 >= 2){
                // cerr << i << " " << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;


}
