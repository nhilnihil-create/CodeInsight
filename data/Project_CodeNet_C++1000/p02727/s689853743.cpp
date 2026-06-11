// 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    REP(i, A) cin >> p[i];
    REP(i, B) cin >> q[i];
    REP(i, C) cin >> r[i];

    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    vector<ll> vec(X+Y);
    for (int i = 0; i < X; ++i)
    {
        vec[i] = p[i];
    }
    for (int i = X; i < X + Y; ++i)
    {
        vec[i] = q[i - X];
    }
    sort(vec.begin(), vec.end());
    int idxr = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it >= r[idxr]) break;
        *it = r[idxr];
        ++idxr;
        if (idxr >= r.size()) break;
    }
    
    ll ans = 0;
    for (const ll& v : vec)
    {
        ans += v;
    }
    cout << ans << endl;
    return 0;
}
