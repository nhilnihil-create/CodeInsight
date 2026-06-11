#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  long long int a,b;
  cin >> a >> b;
  cout << a * b / __gcd(a,b) << endl;
}

