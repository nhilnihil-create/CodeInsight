#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll X,i,S=100;
  cin>>X;
  for (i=0;S<X;i++) {
    S += S/100;
  }
  cout<<i<<endl;
  return 0;
}
