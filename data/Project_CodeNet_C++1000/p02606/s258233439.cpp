#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int l,r,d;
     cin>>l>>r>>d;
     int x=r/d;
     int y=l/d;
     int ans=x-y;
     if(l%d==0)
     ans=ans+1;
     cout<<ans<<endl;
    return 0;
}
