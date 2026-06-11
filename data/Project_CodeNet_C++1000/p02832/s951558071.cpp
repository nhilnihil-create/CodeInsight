#include<iostream>
#include <map>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; ++i)
cin>>arr[i];
int s[n];
for(int i=0; i<n; ++i)
s[i]=i+1;
int k(0);
for(int i=0; i<n; ++i)
{
if(arr[i]==s[k])
++k;
}
cout<<(n-k==n?-1:n-k);
}
