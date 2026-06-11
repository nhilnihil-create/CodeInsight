 
#include<bits/stdc++.h>

using namespace std;

int main()
{
string n;
  cin>>n;
  int rem;
 long long  int sum=0;
  for(int i=0;i<n.length();i++){
   
    
    sum+=n[i]-'0';
       
  }
  
  if(sum%9==0)
    cout<<"Yes";
  else
    cout<<"No";
  
return 0;
  
}
