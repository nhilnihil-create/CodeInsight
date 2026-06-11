#include <bits/stdc++.h>
using namespace std;
int main()
{
int n=0 , k=0 ,sum =0,i=0;
cin>>n>>k;
int arr [n];
for( int m =0 ; m<n ; m++){cin>>arr[m];}
sort(arr,arr+n);
while (i<k)
{
 sum+=arr[i]; i++;   
}
cout<<sum;
}