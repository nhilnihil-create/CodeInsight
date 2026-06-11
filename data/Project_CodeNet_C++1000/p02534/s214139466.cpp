#include<iostream>
#include<string>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  int k;
  cin>>k;
  string s="ACL";
  string s1="ACL";
  for(int i=0;i<k-1;i++)
    s1+=s;
  cout<<s1<<'\n';
  return 0;
}
