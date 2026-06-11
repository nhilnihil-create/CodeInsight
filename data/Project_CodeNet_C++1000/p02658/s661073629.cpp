#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef string str;

#define MAX 1000000000000000000ULL

ll mul(ll a, ll n, bool& no) {
    if (n == 0) {no=false;return 0;}
    if (no) return 0;
    if (a > MAX/n) {no = true;return 0;}
    ll r = a * n;
    return r;
}
int main() {
    int n;
    cin >> n;

    ll r = 1;
    bool no = false;
    for (int i=0;i<n;i++) {
        ll x; cin >> x;
        r = mul(r, x, no);
    }
    if (r > MAX || no) cout << "-1"<<endl;
    else cout<<r<<endl;
}
