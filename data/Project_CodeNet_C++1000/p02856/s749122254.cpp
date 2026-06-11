#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll mod = 1000000007;
const int MAX = 1000100;

int main(){
    int m; cin >> m;
    ll s = 0, d = 0;
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        s += a * b;
        d += b;
    }
    cout << d - 1 + (s - 1) / 9 << endl;
}