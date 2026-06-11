#include<iostream>
using namespace std;
int main (void)
{int n,k,i;
 i=0;
  cin>>n>>k;
 while(n>=1){n=n/k;i++;}
  cout<<i;
}