#include<iostream>
using namespace std;

int main() {
  string S,T;
  cin>>S>>T;
  cout<<(S == T.substr(0,T.size()-1) ? "Yes" : "No")<<endl;
  return 0;
}
