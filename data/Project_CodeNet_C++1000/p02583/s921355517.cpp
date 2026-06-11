#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, m, n) for (int i = m; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    int c = 0;
    rep(i, n -2) repi(j, i+1, n-1) repi(k, j+1, n) {
        if (l[i] != l[j] && l[j] != l[k] && l[i] != l[k]) {
            int maxL = max(l[i], max(l[j], l[k]));
            if (maxL < l[i] + l[j] + l[k] - maxL) {
                c++;                
            }
        }
    }

    println(c)
    return 0;
}