#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; // trick to explore an implicit 2D grid
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // S,SE,E,NE,N,NW,W,SW neighbors  //GO FOR EVEN FOR 4 moves

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
vector<LL> v, sum;
LL sz;
bool possible(LL check, LL extra, LL val)
{
   // part;
    auto lower = lower_bound(v.begin(), v.end(), check);
    LL pos = lower - v.begin();
    LL last = pos - 1;
    LL uninvolved = sz - val;
    //debug(pos);
    //debug(check);
    //debug(pos);
    //debug(last);
    //debug(uninvolved);
    LL needed = check*(last-uninvolved)-(sum[last] - sum[uninvolved]);
    //debug(needed);
   // debug(extra);
    if (needed <= extra)
    {
       // cout << "returning true" << endl;
        return true;
    }
    else
    {
       // cout << "returning false" << endl;

        return false;
    }
}
int main()
{
    fastinput;
    LL n, i, j, k, t, temp, tc;
    cin >> n;
    map<LL, LL> freq;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        freq[j]++;
    }
    for (auto x : freq)
    {
        v.pb(x.second);
    }
    v.pb(0);
    sort(all(v));
    sz = v.size();
    sum.resize(sz);
    sum[0] = 0;
    sz--;
    for (i = 1; i <= sz; i++)
    {
        sum[i] = sum[i - 1] + v[i];
    }

    for (i = 1; i <= n; i++)
    {
        LL now = i;
        LL each_max = n / now;
        LL ans = 0;
        if (freq.size() < i)
        {
            ans = 0;
        }
        else
        {
            LL extra_got = sum[sz - now];
            LL lb = 1, ub = each_max;
            LL mid;
            ans=0;
            while (lb <= ub)
            {
                mid = (lb + ub) / 2;
                if (possible(mid, extra_got, now))
                {
                    ans = mid;
                   // debug(mid);
                    //cout<<"possible"<<endl;
                    lb = mid + 1;
                }
                else
                {
                    ub = mid - 1;
                }
            }
        }
       // debug(now);
        cout<<ans<<endl;
        //part;
        //part;
    }

    return 0;
}
