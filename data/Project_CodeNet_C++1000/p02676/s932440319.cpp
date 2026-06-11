#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int len = s.length()>=n ? n : s.length();
  for(int i = 0 ; i < len ; i++)cout<<s[i];
  if(n>=s.length())
    return 0;
  cout<<"..."<<endl;
}

