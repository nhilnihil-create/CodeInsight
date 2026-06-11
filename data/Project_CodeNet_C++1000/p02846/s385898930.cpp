#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

int main()
{
    Lint t[2],a[2],b[2];
    cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];

    Lint X=(a[0]-b[0])*t[0];
    Lint Y=(a[1]-b[1])*t[1];
    if(X>0) X=-X,Y=-Y;

    if(X+Y<0) cout<<0<<endl;
    else if(X+Y==0) cout<<"infinity"<<endl;
    else{
        Lint ans=(-X)/(X+Y)*2+((-X)%(X+Y)!=0);
        cout<<ans<<endl;
    }
    return 0;
}