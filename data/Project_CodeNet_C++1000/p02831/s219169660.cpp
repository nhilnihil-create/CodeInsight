#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long A, B;
  cin >> A >> B;
  for (int i = 1; i <= B; i++) {
    if ((A * i) % B == 0) {
      cout << A * i << endl;
      break;
    }
  }
}
