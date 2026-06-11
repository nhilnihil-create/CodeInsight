#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  int i = sqrt(n);
  for(;i > 0;i--) if(n % i == 0) break;
  cout << i + n / i - 2 << endl;
}


