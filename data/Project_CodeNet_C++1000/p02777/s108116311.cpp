#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {

  string s1,s2;cin>>s1>>s2;
  int a,b;cin>>a>>b;
  string u;cin>>u;
  
  if(s1==u){
    cout<<a-1<<" "<<b<<endl;
  }
  else{
    cout<<a<<" "<<b-1<<endl;
  }
}