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

ll n;
v1 b;
v1 a;

int main(){
    cin >> n;
    b = v1(n+1);
    a = v1(n+1);
    for(ll i = 1;i < n;i++){
        cin >> b[i];
    }
    b[0] = 1000000;
    b[n] = 1000000;
    for(ll i = 0;i < n;i++){
        a[i] = min(b[i], b[i+1]);
    }
    cout << accumulate(a.begin(),a.end(),0ll) << endl;
}
