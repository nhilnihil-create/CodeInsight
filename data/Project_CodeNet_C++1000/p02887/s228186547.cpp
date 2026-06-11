#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,c=0;
  cin>>a;
  vector<char> b(a);
  for(int i=0;i<a;i++){
    cin>>b.at(i);
  }
  for(int i=0;i<a-1;i++){
    if(b.at(i)==b.at(i+1)){
      c++;
    }
  }
  cout<<a-c<<endl;
}