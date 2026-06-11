#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    ll  t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    ll y1 = (a1-b1)*t1;
    ll y2 = (a2-b2)*t2;

    if (y1 > 0)
    {
        y1 *= -1LL;
        y2 *= -1LL;
    }

    if (y1 +y2 < 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    // cout << "**" << endl;
    if (y1 + y2 == 0)
    {
        cout << "infinity" << endl;
        return 0;
    }
    ll d = y1+y2;
    ll cnt = llabs(y1/d)*2LL + 1LL;
    // cout << "******" << endl;
    // cout << y1 << " " << d << endl;
    if (y1%d == 0) --cnt;
    cout << cnt << endl;


    return 0;
}