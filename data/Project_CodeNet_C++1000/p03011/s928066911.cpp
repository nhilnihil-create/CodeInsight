#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    int p,q,r,x,y,z;
    cin >> p >> q >> r;
    x = p + q;
    y = q + r;
    z = r + p;
    cout << min(x,min(y,z));
}
