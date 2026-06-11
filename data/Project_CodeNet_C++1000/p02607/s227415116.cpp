#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,c=0;
  cin>>a;
  vector<int> b(a);
  for(int i=0;i<a;i++){
    cin>>b.at(i);
  }
  for(int i=0;i<a;i+=2){
    if(b.at(i)%2==1)c++;
  }
  cout<<c<<endl;
}