#include<iostream>
using namespace std;
int main()
{
  int H1,H2,M1,M2,K,t;
  cin>>H1>>M1>>H2>>M2>>K;
  t=M2-M1+60*(H2-H1)-K;
  cout<<t;
}