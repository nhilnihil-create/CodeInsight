#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s,t;
  cin>>s;
  cin>>t;
  int x=s.size();
  string y=t.erase(x);
  if(s==y){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}