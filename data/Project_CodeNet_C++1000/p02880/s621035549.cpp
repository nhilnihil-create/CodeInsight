#include<bits/stdc++.h>
#include<math.h>
const double PI = acos(-1);
using namespace std;
int main()
{
  long int n;
  cin>>n;
  int flag=0;
  for(int i=1;i<10;i++)
  {
      for(int j=1;j<10;j++)
      {
          if(i*j==n){
          flag=1;
    
              break;
          }
      }
  }
  
  if(flag==1)
  cout<<"Yes";
  else 
  cout<<"No";
  

    
}