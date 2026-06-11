//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,c,i,j,misplaced=0;
    cin>>a>>b>>c;
    if(a-b<=0)
        cout<<c<<endl;
    else
        cout<<max(0*1ll,c-(a-b))<<endl;
    return 0;
}



