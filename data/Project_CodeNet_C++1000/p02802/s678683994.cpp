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
#define all(a)                  a.begin(),a.end()
#define FASTIO                  ios_base::sync_with_stdio(0);cin.tie(NULL);

int main()
{
    FASTIO

    int  n, m;
    cin >> n >> m;

    bool AC[100050];
    memset(AC, false, sizeof AC);

    map<int, int> WA;

    FOR (0, m)
    {
        int submission;
        string verdict;

        cin >> submission;
        cin >> verdict;

        if (verdict == "AC")
            AC[submission] = true;
        if (verdict == "WA")
        {
            if (!AC[submission])
                WA[submission]++;
        }
    }

    int ACCOUNT=0, WACOUNT =0;

    for (auto it: WA)
    {
        if (AC[it.first])
        {
            ACCOUNT++;
            WACOUNT += it.second;
            AC[it.first] = false;
        }
    }

    for (int i=0; i<=n; i++)
        if (AC[i])
            ACCOUNT++;
    cout << ACCOUNT << " " << WACOUNT;

}
