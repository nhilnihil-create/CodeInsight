#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
   long long int n;
   cin>>n;
   long long int arr[n+1],arr1[n+1];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
       arr1[arr[i]-1]=i+1;
   }
   for(int i=0;i<n;i++)
   {
       cout<<arr1[i]<<" ";
   }
   cout<<endl;
}
