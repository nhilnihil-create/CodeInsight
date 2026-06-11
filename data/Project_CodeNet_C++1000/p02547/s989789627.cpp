#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n,c=0;cin>>n;int a[n][2];
      for(int i=0;i<n;i++)
      {
       cin>>a[i][0]>>a[i][1];   
      }
      for(int i=0;i<n-2;i++)
      {
          if(a[i][0]==a[i][1]&& a[i+1][0]==a[i+1][1] && a[i+2][0]==a[i+2][1])
          {
              c=1;
              cout<<"Yes";break;
          }
          
      }
      if(c==0)
      cout<<"No";
     
}



 