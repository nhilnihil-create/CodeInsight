#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

signed main(){
    io();
    int a, b, c; cin >> a >> b >> c;
    int x =  a + b + c;
    cout << (x >= 22 ? "bust":"win") << '\n';
    return 0;
}