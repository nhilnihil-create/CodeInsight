#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int a,b,v,w;
  long long int t;
  cin>>a>>v>>b>>w>>t;
  a=abs(a-b);
  b=(v-w)*t;
  if(a<=b)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}