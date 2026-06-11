#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  long long N;
  cin >> N;

  long long a[N];
  for (long long i = 0; i < N; ++i)
    cin >> a[i];

  long long rets[N];
  long long c = 0;
  for (int i = N; i > 0; --i) {
    long long x = 0;
    for (long long j = 2; j <= N / i; ++j) {
      x += rets[i * j - 1];
    }
    if (x % 2 == 0 && a[i - 1] == 0)
      rets[i - 1] = 0;
    else if (x % 2 == 0 && a[i - 1] == 1)
      rets[i - 1] = 1;
    else if (x % 2 == 1 && a[i - 1] == 0)
      rets[i - 1] = 1;
    else if (x % 2 == 1 && a[i - 1] == 1)
      rets[i - 1] = 0;
    if (rets[i - 1] == 1)
      ++c;
  }

  cout << c << endl;
  bool first = true;
  if (c > 0) {
    for (long long i = 0; i < N; ++i) {
      if (rets[i] == 1) {
        if (!first)
          cout << " ";
        cout << i + 1;
        first = false;
      }
    }
    cout << endl;
  }

  return 0;
}