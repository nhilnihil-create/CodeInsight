#include<iostream>
using namespace std;

int main() {
  int K,A,B,i;
  cin>>K>>A>>B;
  for (i=1;i*K<A;i++){}
  cout<<(i*K<=B ? "OK" : "NG")<<endl;
  return 0;
}
