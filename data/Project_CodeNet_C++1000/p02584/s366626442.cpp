#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    
    ll dir = x / abs(x);
    ll target1 = x - abs(x) / d * d * dir;
    ll target2 = x - (1 + abs(x) / d) * d * dir;
    ll target = abs(target1) <= abs(target2) ? target1 : target2;
    
    ll kr = abs(target - x) / d;
    if (k <= kr) {
        put(abs(x - dir * k * d));
    }
    else if ((kr - k) % 2 == 0) {
        put(abs(target));        
    }
    else {
        put(min(abs(target+d), abs(target-d)));        
    }

    return 0;
}