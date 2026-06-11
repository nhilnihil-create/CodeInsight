#include <bits/stdc++.h>
#define ll long long int
#define ld long double
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
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];

    vector<int> a(n);
    a[0] = b[0];
    a[n -1 ] = b[n-2];

    repi(i, n - 1) {
        a[i] = min(b[i], b[i-1]);
    }

    put(accumulate(all(a), 0));    

    return 0;
}