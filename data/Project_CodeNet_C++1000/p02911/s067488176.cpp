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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(q);
    rep(i, q) cin >> a[i];
    
    vector<int> A(n);
    rep(i, q) A[a[i] - 1]++;


    rep(i, n) {
        yorn(k - (q - A[i]) > 0);
    }

    return 0;
}