#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  ll n;
  cin>>n;
  
  ll arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  ll ans = 1000;
  ll temp = ans;
  ll share = ans/arr[0];
  
  ans = ans - share*arr[0];
  
  for(int i=1;i<n;i++)
  {
     if(arr[i]>arr[i-1]){
        ans += share*arr[i];
        temp = ans;
        share = ans/arr[i];
        ans = ans - share*arr[i];
     }
     else if(arr[i]<arr[i-1]){
        ans = temp;
        share = ans/arr[i];
        ans = ans - share*arr[i];
     }
  }
        cout<<temp;
}
