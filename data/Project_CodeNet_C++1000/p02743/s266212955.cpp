#include<bits/stdc++.h>
#define M 1000000007

using namespace std;
typedef long long int ll;

int main()
{
   long double a,b,c;
   cin>>a>>b>>c;
   ll d = c -a-b;
   if(d>0 && d*d>4*a*b)
    cout<<"Yes\n";
   else
    cout<<"No\n";

}
