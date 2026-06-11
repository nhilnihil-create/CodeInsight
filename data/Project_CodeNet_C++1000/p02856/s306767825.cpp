#include<iostream>
using namespace std;
#define int long long
int32_t main()
{
  int d,c;
  int M;
  cin>>M;
  int order=0,sum=0;
  for(int i=0;i<M;i++)
  {
    cin>>d>>c;
    order+=c;
    sum+=(d*c);
  }
  cout<<(order-1)+((sum-1)/9)<<endl;
  return 0;
}