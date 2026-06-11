#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  int a,b,sum1,sum2;
  while(cin>>n){
  for(int i=1;i<=n;i++){
    cin>>a>>b;
    if(a>b) {sum1=sum1+a+b;}
    else if(a<b) {sum2=sum2+a+b;}
    else if(a==b) {sum1=sum1+a;sum2=sum2+b;}
    }
    if(sum1!=0||sum2!=0){cout<<sum1<<" "<<sum2<<endl;}
    sum1=0,sum2=0;
  }
  return 0;
}