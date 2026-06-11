#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    ll ans = max(a*c, a*d);
    ans = max(ans, max(b*c, b*d));
    
    cout << ans << endl;
    
    return 0; 
}