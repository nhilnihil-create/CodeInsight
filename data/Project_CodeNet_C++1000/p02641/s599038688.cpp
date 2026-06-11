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
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    
    unordered_set<int> us;
    rep(i, p.size()) us.emplace(p[i]);

    int best = 0;
    int cost = 1e8;
    rep(i, 102) {
        if (us.count(i) <= 0) {
            int c = abs(x - i);
            if (c < cost) {
                best = i;
                cost = c;
            }
        }
    }

    put(best);

    return 0;
}