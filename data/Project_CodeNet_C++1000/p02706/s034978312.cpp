#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    int sum = 0;
    rep(i, m) sum += a[i];
    if (sum > n) {
        put(-1)
    }
    else {
        put(n - sum);
    }
    return 0;
}