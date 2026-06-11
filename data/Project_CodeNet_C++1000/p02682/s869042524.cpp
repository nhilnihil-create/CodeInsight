#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    long long int a,b,c,k;
    cin>>a>>b>>c>>k;
    if(a>=k)
        cout<<k<<endl;
   else  if(a+b<k)
    {
        cout<<(a+(k-a-b)*(-1))<<endl;
    }
    else if(a+b>=k)
    {
        cout<<a<<endl;
    }

   return 0;
}
