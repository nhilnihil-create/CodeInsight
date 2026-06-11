#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, k, d;
    cin >> n >> k >> d;
    n = abs(n);
    ll need = n / d;
    if (need > k)
    {
        n -= d * k;
        cout << n << endl;
    }
    else
    {
        n -= need * d;
        k -= need;
        //cout<<n<<" "<<k<<" "<<d<<endl;
        ll a = n;
        ll b = abs(n - d);
        //cout<<a<<" "<<b<<endl;
        if (k & 1)
        {
            cout << b << endl;
        }
        else
            cout << a << endl;
    }
}
