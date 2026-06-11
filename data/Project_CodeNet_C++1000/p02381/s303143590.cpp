#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
  while(1)
  {
    int n;
    cin>>n;
    if(n==0) break;
    int s[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
      cin>>s[i];
      sum+=s[i];
    }
    double dev=0;
    for(int i=0;i<n;i++)
    {
      dev+=pow(s[i]-sum*1.0/n,2);
    }
    cout<<fixed<<sqrt(dev/n)<<endl;
  }
}