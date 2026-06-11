#include <iostream>

using namespace std;

int main() {
  int l, r, d, min, max;
  int p = 0;
  cin>>l>>r>>d;
  min = l/d;
  max = r/d;
  if(float(l)/float(d) == float(l/d)){
    p = 1;
  }
  cout<<max - min + p;
}