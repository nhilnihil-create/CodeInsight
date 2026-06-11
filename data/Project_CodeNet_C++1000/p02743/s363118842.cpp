#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
   ll a,b,c;
   cin>>a>>b>>c;
   ll s=c-a-b;
   if(s>0&&(4*a*b)<(s*s))cout<<"Yes";
   else
    cout<<"No";
    return 0;
}





