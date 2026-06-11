#include<iostream>
using namespace std;
int main()
{
  int a,ans=0;
   cin>>a;
  int aa[a];
  for(int i=0;i<a;i++)
  {
   cin>>aa[i];
    if(aa[i]%2==1 && i%2!=1)
      ans++;
  }
  cout<<ans<<endl;
}
