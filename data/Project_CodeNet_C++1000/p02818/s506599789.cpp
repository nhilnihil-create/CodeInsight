#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (k <= a) {
        cout << (a - k) << " " << b << endl;
    }
    else if (k <= a + b) {
        cout << 0 << " " << (a + b - k) << endl;
    }
    else {
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}