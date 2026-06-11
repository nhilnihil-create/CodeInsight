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
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < n - 2; ++i)
        cnt += (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');
    cout << cnt << '\n';
    return 0;
}