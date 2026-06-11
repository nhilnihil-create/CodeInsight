#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
  int n, rem, sum,mod;
  cin>>n;
  if(n%1000==0)
  {
    cout<<"0"<<endl;
  }
  else
  {
    rem=n/1000;
    mod=n%1000;
    sum=1000-mod;
    cout<<sum<<endl;
  }
}