#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  int d=0;
  vector<string> b(a);
  vector<int> c(a);
  for(int i=0;i<a;i++){
    cin>>b.at(i)>>c.at(i);
  }
  string e;
  cin>>e;
  for(int i=a-1;i>=0;i--){
    if(b.at(i)==e){
      break;
    }
    d+=c.at(i);
  }
  cout<<d<<endl;
}