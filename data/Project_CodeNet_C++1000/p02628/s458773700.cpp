#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  
  for(int i=0;i<n;i++)
    cin>>a[i];
  
  sort(a,a+n);
  int min_sum=0;
  for(int i=0;i<k;i++)
  {
    min_sum+=a[i];
  }
  
  cout<<min_sum<<"\n";
    return 0;
}
