// 問題の URL を書いておく
// https://atcoder.jp/contests/abc160/tasks/abc160_e

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(int, const char**)
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int64_t> p(a, 0);
    rep(i, a) cin >> p[i]; 
    vector<int64_t> q(b, 0);
    rep(i, b) cin >> q[i]; 
    vector<int64_t> r(c, 0);
    rep(i, c) cin >> r[i]; 

    sort(p.begin(), p.end(), greater<int64_t>());
    sort(q.begin(), q.end(), greater<int64_t>());
    sort(r.begin(), r.end(), greater<int64_t>());

    p.resize(x);
    q.resize(y);
    r.resize(min(x + y, c));

    priority_queue<int64_t> pq;
    for(auto t : p) pq.push(t);
    for(auto t : q) pq.push(t);
    for(auto t : r) pq.push(t);

    int64_t ans = 0;
    rep(i, x + y)
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
