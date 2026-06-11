#include<iostream>
#include<algorithm>
#ifndef ONLINE_JUDGE
#define line cout<<"here - "<<__LINE__<<"\n";
#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
#else
#define line
#define dbg(a)
#endif
using namespace std;
main()
{
    //fast
    int tc=1,i,j,k;
    while(tc--)
    {
       int a;
       cin>>a;
       int x=__gcd(a,360);
       x=a/x;
       x*=360;
       cout<<x/a<<endl;
    }
}


