#include<iostream>
using namespace std;
int main()
{
  
  int i,j,k,n;
  string str;
  cin>>str;
  if(str[str.size()-1]=='s')cout<<str<<"es"<<endl;
  else cout<<str<<"s"<<endl;
  return 0;
}
