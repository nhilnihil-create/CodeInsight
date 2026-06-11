//Atcoder solution
#include<iostream>
using namespace std;

void solve(int a,int b,int c)
{
  int sum;
  sum=a+b+c;

  if(sum>=22)
  {
  	cout<<"bust"<<endl;
  }
  else
  	cout<<"win"<<endl;
}
int main()
{
  int a,b,c;
  cin>>a>>b>>c;

  solve(a,b,c);
}