#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  vector<int>vec;
  cin>>a>>b;
  vec.push_back(a);
  vec.push_back(b);
  cout<<6-vec.at(0)-vec.at(1)<<endl;
  return 0;
}
