#include<bits/stdc++.h>
#include<string>
#include<cmath>
using namespace std;

#define ll long long int

int main(){
ll a,b,k;cin>>a>>b>>k;
if(a>=k)
  cout<<a-k<<" "<<b<<endl;
else
{
  if(b>=(k-a))
    cout<<"0"<<" "<<b-k+a;
  else
  {
     cout<<"0"<<" "<<"0"<<endl;
  }  
}
}