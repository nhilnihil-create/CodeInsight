#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,k;
	int cnt=0;
  cin>>a>>b>>c>>k;
  while(a>=b)
  {
    cnt+=1;b*=2;
  }
  while(b>=c)
  {
    cnt+=1;c*=2;
  }
  if(cnt<=k)cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}