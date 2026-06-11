#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n , k , d ;
    cin >>  n >> k >> d;
    if(n==0)
    {
        if(k%2==0)
            cout << 0 ;
        else cout << d;
        return 0;
    }
    n=abs(n);
    ll x = min(n/d , k);
    n-=(x*d);
    k-=x;
    if(k%2==0)
        cout << n;
    else cout << d-n;
    return 0;
}
