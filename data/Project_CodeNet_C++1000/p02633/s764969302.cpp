#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int x;
    cin>>x;
    int y=360;
    int z=__gcd(x,y);
    int res=(x*y)/z;
    res=res/x;
    cout<<res<<"\n";
}