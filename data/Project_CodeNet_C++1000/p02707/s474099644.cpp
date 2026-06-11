#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int arr[n]={0};
   int ara[n];
   for(int i=0;i<n-1;i++)
   {
       cin>>ara[i];
   }
   for(int i=0;i<n-1;i++)
   {
       int x=ara[i];
       arr[x-1]++;
   }
   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    return 0;
}
