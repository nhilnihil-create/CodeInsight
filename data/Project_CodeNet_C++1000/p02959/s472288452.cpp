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

    int n;
    cin >> n;

    vector <int> monstar, hero;

    FOR (0, n+1)
    {
        long long buf;
        cin >> buf;
        monstar.push_back(buf);
    }

    FOR (0, n)
    {
        long long buf;
        cin >> buf;
        hero.push_back(buf);
    }

    long long ans = 0;

    FOR (0,n)
    {

        if (hero[i] >= monstar[i])
        {
            ans += monstar[i];
            hero[i] -= monstar[i];
            monstar[i] = 0;
            if (hero[i] >= monstar[i+1])
            {
                ans += monstar[i+1];
                monstar[i+1] = 0;
            }
            else
            {
                ans += hero[i];
                monstar [i+1] = monstar[i+1] - hero[i];
            }
        }
        else
        {
            ans += hero[i];
        }
    }

    cout << ans;

}

