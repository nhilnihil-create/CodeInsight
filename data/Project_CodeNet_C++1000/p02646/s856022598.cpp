#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int a,b,v,w,t;
  cin>>a>>v;
  cin>>b>>w;
  cin>>t;
  long long int d = abs(a-b);
  long long int d1 = (v-w)*t;
  if(d<=d1)
    cout<<"YES"<<endl;
 else 
   	cout<<"NO"<<endl;
}
