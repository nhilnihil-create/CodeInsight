#include<bits/stdc++.h>
using namespace std;
int main()
{
  long int n;
  cin>>n;
  long long int sum=0;
  long int x=n/500;
  sum=1000*x;
  x=n%500;
  sum+=5*(x/5);
  cout<<sum;
}