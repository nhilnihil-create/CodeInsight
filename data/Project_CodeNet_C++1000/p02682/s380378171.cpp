#include<iostream>
using namespace std;

int main() {
  int A,B,C,K,ans;
  cin>>A>>B>>C>>K;
  if (K<=A) ans=K;
  else if (K<=A+B) ans=A;
  else ans=2*A+B-K;
  cout<<ans<<endl;
  return 0;
}
