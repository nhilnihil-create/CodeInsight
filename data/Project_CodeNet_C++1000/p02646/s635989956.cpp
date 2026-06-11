#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    ll d = a>=b?a-b:b-a;
    cout << (d<=t*(v-w)?"YES\n":"NO\n");
    return 0;
}
