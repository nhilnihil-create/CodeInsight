#include<iostream>
using namespace std;

int main() {
  int X,i;
  cin>>X;
  for (i=1;i<=360;i++) {
    if (X*i%360 == 0) break;
  }
  cout<<i<<endl;
  return 0;
}
