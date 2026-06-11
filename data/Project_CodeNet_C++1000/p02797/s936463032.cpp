#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n, k,s;
   cin>>n>>k>>s;
   ll a[n];
   for(int i=0;i<k;i++)
   {
       a[i] = s;
   }
   ll temp =1000000000;
   if( s == temp)
       temp =999999999;



   for(int i=k;i<n;i++)
   {
       a[i] = temp;
   }
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }
}