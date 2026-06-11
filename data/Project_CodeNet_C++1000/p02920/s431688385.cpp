// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
const int INF = (int)2e9 + 1;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, temp;
  cin >> N;

  vector<int> seq;
  vector<int> slime;

  int n2 = 1 << N;
  for (int i = 0; i < n2; i++) {
    cin >> temp;
    seq.push_back(temp);
  }
  sort(seq.begin(), seq.end());
  slime.push_back(seq.back());
  seq.back() = -INF;
  int cnt;

  for (int i = 0; i < N; i++) {
    vector<int> pre = slime;
    sort(pre.begin(), pre.end());
    cnt = n2 - 1;
    while (pre.size() > 0 && cnt >= 0) {
      if (seq[cnt] == -INF) {
        cnt--;
        continue;
      }
      if (seq[cnt] < pre.back()) {
        slime.push_back(seq[cnt]);
        pre.pop_back();
        seq[cnt] = -INF;
      }
      cnt--;
    }
    if (!pre.empty()) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}