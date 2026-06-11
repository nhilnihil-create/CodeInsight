#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,i, x, y, zmin=2e9, zmax=-2e9, wmin=2e9, wmax=-2e9;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        zmax = max(zmax, x+y);
        zmin = min(zmin, x+y);
        wmax = max(wmax, x-y);
        wmin = min(wmin, x-y);
    }
    cout<<max(zmax-zmin, wmax-wmin)<<endl;
}
int main() {
    int t=1;
    //cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}