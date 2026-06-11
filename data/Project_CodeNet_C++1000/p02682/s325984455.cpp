#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main() 
{
int a,b,c,k;
cin>>a>>b>>c>>k;

if(a>=k)
{
          cout<<k<<"\n";
}
else
if((a+b)>=k)
{
          cout<<a<<"\n";
}
else
{
          cout<<(a-(k-(a+b)))<<"\n";
}
}
