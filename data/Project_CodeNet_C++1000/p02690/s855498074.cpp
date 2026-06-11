#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll X,a,b;
  cin>>X;
  bool cont = true;
  for (a=-1000;a<=1000 && cont;a++) {
    for (b=-1000;b<=1000 && cont;b++) {
      if (X == (a*a*a*a*a - b*b*b*b*b)) cont = false;
    }
  }
  cout<<a-1<<" "<<b-1<<endl;
  return 0;
}
