#include <bits/stdc++.h>
using namespace std;

vector<long long> d(long long n) {
  vector<long long> numbers;
  for (long long i=1; i<=sqrt(n); i++) {
    if (n % i == 0) {
      numbers.push_back(i);
      if (i != n / i) {
        numbers.push_back(n / i);
      }
    }
  }
  return numbers;
}

int main() {
  long long n;
  cin>>n;
  int cnt = d(n-1).size() - 1;
  for (long long a: d(n)) {
    if (a == 1) {
      continue;
    }
    long long m = n;
    while (m % a == 0) {
      m /= a;
    }
    if (m % a == 1) {
      ++cnt;
    }
  }
  cout<<cnt<<endl;
}