#include <iostream>

using namespace std;

int main(void)
{
  int k,n,i,max,ans;
  cin>>k>>n;
  int a[200000];
  
  for(i=0;i<n;i++){cin>>a[i];}
   
  int b[200000];
 for(i=0;i<n-1;i++){b[i]=a[i+1]-a[i];}
  b[n-1]=a[0]+k-a[n-1];
  max=0;
for(i=0;i<n;i++) {if(b[i]>max)max=b[i];}
  ans=k-max;
  cout<<ans<<endl;
	return 0;

}