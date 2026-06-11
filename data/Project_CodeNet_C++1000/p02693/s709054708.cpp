#include<iostream>
using namespace std;

int main() {
  int K,A,B;
  cin>>K>>A>>B;
  cout<<(A<=(B/K)*K ? "OK" : "NG")<<endl;
  return 0;
}
