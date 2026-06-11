#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>
// 追加１
#include <fstream>



using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll mod = 2019;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()


typedef pair<ll, ll> P;

int main()
{
    int N;
    cin >> N;

    vector<P> balls(N);

    rep(i, N)
    {
        cin >> balls[i].first >> balls[i].second;
    }

    sort(all(balls));

    map<P, int> diffs;

    rep(i, N)
    {
        repl(j, i + 1, N)
        {
            ll x = balls[i].first - balls[j].first;
            ll y = balls[i].second - balls[j].second;
            diffs[make_pair(x, y)]++;
        }
    }

    int maxCount = 0;

    for (auto p : diffs)
    {
        if (p.second > maxCount)
        {
            maxCount = p.second;
        }
    }

    cout << N - maxCount << endl;

    return 0;
}