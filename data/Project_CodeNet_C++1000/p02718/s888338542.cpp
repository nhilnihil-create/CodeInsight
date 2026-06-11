#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  
  int n,m,a[100],i,j,k,sum=0;
  cin>>n>>m;
  for(i=0;i<n;i++){cin>>a[i];sum+=a[i];}

  sort(a,a+n,greater<int>());
  j=sum/(4*m);
  if(sum%(4*m)!=0){j++;}
  for(i=0;i<m;i++)
  {
    if(a[i]<j){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}