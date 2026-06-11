#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    if(x<0) x = -x;
    if(x/d >= k) cout << x - k*d;
    else {
        cout << (((k-x/d)%2==0)?x%d: d-x%d); 
    }
}