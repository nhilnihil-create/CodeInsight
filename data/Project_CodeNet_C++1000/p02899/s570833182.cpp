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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    typedef std::pair<int, int> pair;
    vector<pair> p;
    rep(i, n) p.push_back(pair(i+1, a[i]));
    sort(all(p), [](const pair& lhs, const pair& rhs) {
        return lhs.second < rhs.second;
    });
    rep(i, n) {
        put(p[i].first)
    }
    return 0;
}