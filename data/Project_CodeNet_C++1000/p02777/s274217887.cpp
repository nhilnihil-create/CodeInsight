#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2,s3;
  int a,b;
  cin>>s1>>s2;
  cin>>a>>b;
  cin>>s3;
  if(s1.compare(s3)==0)
    cout<<(a-1)<<" "<<b<<endl;
  else if(s2.compare(s3)==0)
    cout<<a<<" "<<(b-1)<<endl;
  }