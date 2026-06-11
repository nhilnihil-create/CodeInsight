#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll gcd(ll a, ll b){
    if(b > a){
        ll x = a;
        a = b;
        b = x;
    }
    ll q, r;
    q = a / b;
    r = a % b;
    if(r == 0) return b;
    return gcd(b, r);
}
int main() {
    ll a, b; cin >> a >> b;
    cout << a * b / gcd(a, b) << endl;
    return 0;
}
