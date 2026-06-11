#include<iostream>
using namespace std;
int main (void)
{
  long long int sum;
  int n,i;
  cin>>n;
  sum=0;
  for(i=0;i<=n;i++){if(i%3!=0&&i%5!=0){sum+=i;}}
  cout<<sum;
  

}