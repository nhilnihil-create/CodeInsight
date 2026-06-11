#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
#define in(v)  for(auto &a: v)cin >> a;
#define out(v) for(auto &a: v)cout << a << sp;cout << en;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll a, b, c, d, ans = -1000000000000000000;
    cin >> a >> b >> c >> d;
    ans = max(ans, a*c);
    ans = max(ans, a*d);
    ans = max(ans, b*c);
    ans = max(ans, b*d);
    cout << ans << en;
    return 0;
}
