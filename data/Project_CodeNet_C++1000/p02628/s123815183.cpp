#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,s=0;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr.begin(),arr.end());
  for(int i=0;i<k;i++)
   s=s+arr[i];
  cout<<s;
}