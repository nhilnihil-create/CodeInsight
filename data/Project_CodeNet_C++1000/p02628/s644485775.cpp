#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr) / sizeof(value), (value))

template <typename T>
void FILL_(void* ptr, size_t size, T value) {
  std::fill((T*)ptr, (T*)ptr + size, value);
}

inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int p[n] = {};
  for(int i=0;i<n;++i)
  {
    cin >> p[i];
  }
  sort(p, p + n);

  cout << accumulate(p, p + k, 0) << endl;

}