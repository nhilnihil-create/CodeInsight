#include<iostream>
using namespace std;

int main() {
  int K;
  string S;
  cin>>K>>S;
  if (K < S.size()) {
    S = S.substr(0,K) + "...";
  }
  cout<<S<<endl;
  return 0;
}
