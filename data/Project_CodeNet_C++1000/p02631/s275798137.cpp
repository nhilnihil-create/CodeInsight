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
  int n;
  cin >> n;
  int a[n] = {};
  int bit_count[32] = {};
  for(int i=0;i<n;++i)
  {
    cin >> a[i];
    for(int j=0;j<32;++j)
    {
      if(a[i] & (1 << j))
      {
        bit_count[j] += 1;
      }
    }
  }
  int mask = 0;
  for(int i=0;i<32;++i)
  {
    if(bit_count[i] % 2 == 1)
    {
      mask |= (1 << i);
    }
  }

  for(int i=0;i<n;++i)
  {
    cout << (a[i] ^ mask);
    if(i != n-1)
    {
      cout << " ";
    }
  }
  cout << endl;
}