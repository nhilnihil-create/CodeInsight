#include<bits/stdc++.h>>

using namespace std;
int main()
{
  int n,a[100],flag=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }

  for(int i=0;i<n;i++)
  {
      if(a[i]%2==0 && a[i]%3!=0 && a[i]%5!=0)
      {
          flag=1;
          break;
      }

  }
  if(flag==1)
    cout<<"DENIED";
  else
    cout<<"APPROVED";

   return 0;
}




