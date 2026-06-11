#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5+5 , M = 998244353, OO = 0x3f3f3f3f;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const double Pii = 3.14159265359;
ll n, m;

int main()
{
    FIO
    cin >> n >> m;
    if(n%2 == 1)
    {
        ll st = 1, en = (n/2)*2;
        for(int i=0; i<m; ++i)
        {
            cout << st << " " << en << endl;
            st++; en--;
        }
    }
    else
    {
        vector<ll> v;
        ll d1 = n-1;
        while(d1 > n/2)
        {
            v.push_back(d1);
            d1-=2;
        }
        ll d2 = (n/2)-1;
        if(d2%2 == 1) d2--;
        while(d2 > 0)
        {
            v.push_back(d2);
            d2-=2;
        }
        ll st = 1;
        for(int i=0; i<m; ++i)
        {
            cout << st << " " << st+v[i] << endl;
            st++;
        }
    }

    return 0;
}


