#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,k,m,p;
   cin>>n>>k;
   m = n%k;
   p = abs(m-k);
   if(m<p)
    cout<<m;
   else
    cout<<p;
   return 0;

}
