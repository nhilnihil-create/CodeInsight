#include<iostream>
using namespace std;
int main(){
  string s;
  string t;
  int a;
  int b;
  string u;
  cin>>s;
  cin>>t;
  cin>>a;
  cin>>b;
  cin>>u;
  if(u==s){
    cout<<a-1<<" "<<b<<endl;
  }
  else{
    cout<<a<<" "<<b-1<<endl;
  }
  return 0;
}