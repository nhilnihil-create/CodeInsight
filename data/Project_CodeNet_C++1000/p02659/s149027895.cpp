#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,z;
    double y;
    cin>>x>>y;
    z=y*100+0.1;
    ll num;
    num=(ll)x*z/100;
    cout<<num<<endl;
    return 0;
}
