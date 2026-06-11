#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    int sum = 0;

    if (n >= 10) {
        sum += 9;
    }
    if (n >= 1000) {
        sum += 1000 - 100;
    }
    if (n >= 100000) {
        sum += 100000 - 10000;
    }

    int d = 0;
    int t = n;
    while (t > 0) {
        t /= 10;
        d += 1;
    }
    if (d % 2 == 1) {
        sum += n - pow(10, d-1) + 1;
    }
    put(sum)

    return 0;
}