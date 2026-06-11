#include<iostream>
using namespace std;

int main() {
  int A,B,C,K;
  cin>>A>>B>>C>>K;
  for (;K>0 && B<=A;K--) B*=2;
  for (;K>0 && C<=B;K--) C*=2;
  cout<<(A<B && B<C?"Yes":"No")<<endl;
  return 0;
}
