#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; 
  cin >> n;
  const int kVal = 26;
  string result;
  while (n > 0) {
    char c = (n-1) % kVal + 'a';
    result.push_back(c);
    n = (n-1)/kVal;
  }
  reverse(result.begin(), result.end());
  cout << result << endl;
}
