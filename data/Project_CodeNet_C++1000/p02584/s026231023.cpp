#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll x,k,d;
    cin >> x >> k >> d;
    x = abs(x);
    if(k <= x/d) { cout << x - k*d << endl; return 0;}

    ll lim = x/d;
    if((k + lim) & 1) cout << (lim+1)*d - x << endl;
    else cout << x - lim*d << endl;
    return 0;
}