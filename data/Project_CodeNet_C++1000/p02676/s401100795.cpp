#include<iostream>
using namespace std;
int main()
{
  int n;
  string str;
  cin>>n>>str;
  if(n<str.length())
  {
  cout<<str.substr(0,n)<<"...";
  }
  else cout<<str;
}