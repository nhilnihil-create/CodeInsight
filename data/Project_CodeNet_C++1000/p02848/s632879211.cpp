#include<iostream>
using namespace std;
int main (void)
{
  char c;
  string s;
  int i,j,n;
  cin>>n>>s;
  j=s.size();
  for(i=0;i<j;i++)
  {
    if(s[i]+n<='Z'){c=s[i]+n;}
    else{c=s[i]+n+'A'-'Z'-1;}
    cout<<c;
  }
}