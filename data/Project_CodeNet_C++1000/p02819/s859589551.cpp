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

bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }

    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

signed main()
{
    int x;
    cin >> x;
    for (int i = x; ; i++) {
        if (isPrime(i)) {
            put(i);
            return 0;
        }
    }
    return 0;
}