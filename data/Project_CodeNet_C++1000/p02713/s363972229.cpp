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


int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


signed main()
{
    int k;
    cin >> k;
    ll sum = 0;
    repi(a, k+1)
    repi(b, k+1)
    repi(c, k+1) {
        sum += gcd(gcd(a, b), c);
    }
    put(sum);
    return 0;
}