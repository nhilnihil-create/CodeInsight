#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    int c=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++)
      for(int k=j+1;k<n;k++)
      {
          if(a[i]!=a[j] && a[i]!=a[j] && a[j]!=a[k])
          {
              if(a[i]+a[j]>a[k])
               c++;
          }
      }
    cout<<c<<endl;
}