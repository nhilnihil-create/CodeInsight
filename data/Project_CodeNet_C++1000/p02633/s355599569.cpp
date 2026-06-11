#include<bits/stdc++.h>
using namespace std;
int main()
{
      int n;
      cin>>n;
      int k=1;
      while(1)
      {
        if(k*n%360==0)
           break;
        k++;
      }
      cout<<k<<endl;
   return 0; 
}