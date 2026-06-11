#include<bits/stdc++.h>
using namespace std;
int main(void) {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int rhs = c - a - b;
  if(rhs < 0) {
    cout<<"No\n";
    return 0;
  }
  rhs = rhs * rhs;
  long long int lhs = 4*a*b;
  if(lhs < rhs) {
    cout<<"Yes\n";
  } else {
	cout<<"No\n";
  }
}