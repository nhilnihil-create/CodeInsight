#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  string s,s3;
  s.insert(s.begin(),b,a+'0');
  s3.insert(s3.begin(),a,b+'0');
if(s3<s){cout<<s3<<endl;}
else cout<<s<<endl;
return 0;
}
