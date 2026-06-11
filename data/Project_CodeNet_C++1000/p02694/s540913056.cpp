#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   ll n,s=100,t=0;
   cin>>n;
   while(s<n)
   {
       s=s+(s/100);
       t++;
   }
   cout<<t<<endl;

}
