#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll gcd(ll a, ll b){
    ll c = a%b;
    if(c == 0) return b;
    else return gcd(b,c);
}

ll lcm(ll a, ll b){
    return a*b / gcd(a,b);
}

ll bytwo(ll a){
    if(a%2 == 1) return 0;
    return 1+bytwo(a/2);
}

int main(){
    ll n,m;
    cin >> n >> m;
    map<ll,ll> a;
    for(int i = 0; i < n; i++){
        ll tmp;
        cin >> tmp;
        a[tmp] = 1;
    }

    ll ans = 0;
    ll lcmn = (a.begin()->first/2);
    ll cut = bytwo(a.begin()->first/2);
    for(auto it = a.begin(); it != a.end(); it++){
        lcmn = lcm(lcmn,it->first/2);
        if(bytwo(it->first/2) != cut){
            ans = -1;
            break;
        }
    }

    if(ans == -1){
        ans = 0;
    } else {
        ll tmp = m/lcmn;
        ans = tmp/2 + tmp%2;
    }

    cout << ans << endl;
    return 0;
}