#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    int keta = log10(i) + 1;
    if (keta % 2  ==  1) ++cnt;
  }
  cout << cnt << endl;
}
