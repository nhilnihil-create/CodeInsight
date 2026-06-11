#include<iostream>
using namespace std;
int main(){
  string a,r = "";
  cin>>a;
  for (int i=0; i<a.size();i++){
    r +="x";
  }
  cout<<r<<endl;
  return 0;
}