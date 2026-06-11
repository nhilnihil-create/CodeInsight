// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
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

#define TR() printf("%s(%d)\n", __FILE__, __LINE__)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)
#define TR() ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

const ll MIN = numeric_limits<ll>::min();

ll calc(int start, ll k, vector<int>& p, vector<ll>& c)
{
    int index = start;
    vector<int> indices(p.size());
    vector<ll> scores(p.size());
    ll currentScore = 0;
    ll icount = 0;
    indices.resize(0);
    scores.resize(0);
    // make graph 
    while(true)
    {
        indices.push_back(index);
        currentScore += c[index];
        scores.push_back(currentScore);
        icount++;
        if(p[index] == start)
        {
            break;
        }
        index = p[index];
    }

    ll maxScoreInLoop = MIN;
    for(ll i = 0; i < min(icount, k); ++i)
    {
        maxScoreInLoop = max(maxScoreInLoop, scores[i]);
    }

    auto loopScore = *scores.rbegin();
    if(loopScore < 0)
    {
        return maxScoreInLoop;
    }

    auto d = k / icount;
    auto m = k % icount;
    ll mScore = MIN;
    for(ll i = 0; i < m; ++i)
    {
        mScore = max(mScore, scores[i]);
    }
    auto c0 = d * loopScore + mScore;

    if(d > 0)
    {
        auto c1 = (d - 1) * loopScore + maxScoreInLoop;
        return max(c0, c1);
    }
    return c0;
}

int main(int, const char**)
{
    ll n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n)
    {
        cin >> c[i];
    }

    auto ans = MIN;
    rep(i, n)
    {
        ans = max(ans, calc(i, k, p, c));
    }
    cout << ans << endl;
    return 0;
}
