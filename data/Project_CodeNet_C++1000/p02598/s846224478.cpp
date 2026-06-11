#include<iostream>
using namespace std;
int main()
{
  int n,k,max;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]>max)
      max=a[i];
  }
  int left=1,right=max,result;
  while(left<=right)
  {
    int mid=(left+right)/2;
    int x=0;
    for(int i=0;i<n;i++)
    {
      x+=a[i]/mid;
      if(a[i]%mid==0)
        x--;
    }
    if(x<=k)
    {
      result=mid;
      right=mid-1;
    }
    else
    {
      left=mid+1;
    }
  }

  cout<<result<<endl;
  return 0;
}
