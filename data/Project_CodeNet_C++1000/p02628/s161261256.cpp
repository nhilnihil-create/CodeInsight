#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
   int n,k,sum=0;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   sort(arr,arr+n);
   for(int i=0;i<k;i++)
    sum=sum+arr[i];
   cout<<sum;
}

