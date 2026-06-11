#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c;
  cin >> a >> b >> c;
  if(a+b<c & 4*a*b<(c-a-b)*(c-a-b)) cout << "Yes";
  else cout << "No";
}