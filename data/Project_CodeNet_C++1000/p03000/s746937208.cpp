#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   int n,x;
   cin>>n>>x;
   int arr[n];
   for(int i=0;i<n;i++)
      cin>>arr[i];
   int sum = 0,count = 1;
   for(int i=0;i<n;i++)
   {
      sum += arr[i];
      if(sum<=x)
         count++;
   }
   cout<<count;
   return 0;
}
