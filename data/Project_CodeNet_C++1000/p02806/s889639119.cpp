#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s[n],x;
  int ar[n+1],arr[n+1]={0};
  for(int i=0;i<n;i++)
    cin>>s[i]>>ar[i];
  cin>>x;
  ar[n]=0;
  for(int i=n-1;i>=0;i--)
     arr[i] = ar[i+1]+arr[i+1];
  for(int i=0;i<n;i++)
      if(x==s[i])
        cout<<arr[i]<<endl;
    return 0;
}