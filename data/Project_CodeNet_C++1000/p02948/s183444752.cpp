#include <bits/stdc++.h>

using namespace std;

#define min3(a, b, c)           min((a), min((b), (c)))
#define max3(a, b, c)           max((a), max((b), (c)))
#define lcm(a,b)                (a / __gcd(a,b) ) *b
#define gcd(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define sqr(a)                  ((a)*(a))
#define FOR(a, b)               for(int i=a; i<b; i++)
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define all(a)                  a.begin(), a.end()
#define FASTIO                  ios_base::sync_with_stdio(0);cin.tie(NULL);

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if ((A.ss+A.ff != B.ss+B.ff))
        return A.ss+A.ff > B.ss+B.ff;
    else
        return A.ff > B.ff;
}

bool bmp(pair<int, int> A, pair<int, int> B)
{
    return A.ff > B.ff;
}

int main()
{
    FASTIO

    int n, m;
    vector<int> v[100005];

    cin >> n >> m;

    FOR (0, n)
    {
        int buf, bbuf;
        cin >> buf >> bbuf;
        v[buf].push_back(bbuf);
    }

    priority_queue<int> q;

    long long ans = 0, day = 1;
    for ( ; day <= m; day++)
    {
        for (int k:v[day])
            q.push(k);
        if(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans;
}

