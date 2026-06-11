#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b;
  cin>>a>>b;
  vector<int>v;
  v.push_back(a);
  v.push_back(b);
  
  cout<<6-v.at(0)-v.at(1);
}