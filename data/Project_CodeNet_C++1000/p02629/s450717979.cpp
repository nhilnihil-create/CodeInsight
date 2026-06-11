#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n;
  cin>>n;
  if(n%26==0)
  {
      
  }
  string s="";
  while(n>0)
  {
      n--;
    s+='a'+n%26;
    n/=26;
  }
  reverse(s.begin(),s.end());
  cout<<s;
}