#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,k,i,c,d;
  cin>>a>>b>>k;
  if(a==k) cout<<"0"<<" "<<b<<endl;
  else if(a<k)
  {
    if(b-(k-a)<0) cout<<"0"<<" "<<"0"<<endl;
    else cout<<"0"<<" "<<b-(k-a)<<endl;
  }
  else if(a>k)  cout<<a-k<<" "<<b<<endl;

}
