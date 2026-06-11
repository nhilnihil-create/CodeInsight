#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  int cnt=0;
  for(int i=0;i<3;i++){
    if(a.at(i)==b.at(i)){cnt++;}
  }
  cout<<cnt<<endl;
}
