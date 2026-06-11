#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a;
    vector<int> v(n);
    rep(i, k) {
        int d;
        cin >> d;
        rep (j, d) {
            int a;
            cin >> a;
            v[a-1]++;
        }
    }
    int c = 0;
    rep(i, n) {
        if (v[i] == 0) {
            c ++;
        }
    }
    put(c);
    return 0;
}