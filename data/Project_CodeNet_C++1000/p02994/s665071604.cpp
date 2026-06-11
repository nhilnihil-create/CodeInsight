#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int n,l,i,sum,ans;
  cin>>n>>l;
  sum=0;
  for(i=1;i<=n;i++)
  {
    sum+=(l+i-1);
  }

  if(l>0){sum-=l;}
  else if(l+n-1<0){sum-=l+n-1;}
  cout<<sum<<endl;
  
}