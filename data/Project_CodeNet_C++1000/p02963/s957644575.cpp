#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    const ll maxN = 1000000000;
    ll S;
    cin >> S;
    ll x1, y1, x2, y2, x3, y3;
    x1 = 0;
    y1 = 0;
    x2 = maxN;
    y2 = 1;
    ll p = S / maxN;
    ll q = S % maxN;
    if (q == 0)
    {
        x3 = q;
        y3 = p;
    }
    else
    {
        x3 = maxN - q;
        y3 = p + 1;
    }

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
