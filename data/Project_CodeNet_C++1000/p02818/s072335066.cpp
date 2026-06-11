#include<bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b, k;
  cin >> a >> b >> k;
  if (a>=k) {
    a-=k;
  }
  else if (a<k && b>=k-a) {
    k-=a;
    a=0;
    b-=k;
  }
  else if (a+b<k) {
    a=0;
    b=0;
  }
  cout << a << " " << b << endl;
}