#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rem(i, s, n) for (int i = (s); i >= (n); --i)
using ll = long long;
const int MOD = 1e9+7;

int main(){
    string s, t; cin >> s >> t;
    int a, b; cin >> a >> b;
    string u; cin >> u;

    if(s == u) cout << a - 1 << " " << b << endl;
    else cout << a << " " << b - 1 << endl;

    return 0;
}