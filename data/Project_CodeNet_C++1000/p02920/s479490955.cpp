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
  int n2 = 1 << N;

  vector<int> seq;
  vector<int> slime;
  vector<int> birth;

  for (int i = 0; i < n2; i++) {
    cin >> temp;
    seq.push_back(temp);
  }
  sort(seq.begin(), seq.end());  //昇順
  slime.push_back(seq.back());
  seq.pop_back();
  sort(seq.begin(), seq.end(), greater<int>());  //降順

  for (int i = 0; i < N; i++) {
    int cnt = 0, idx2 = 1 << i;
    for (int j = 0; cnt < idx2 && j < seq.size(); j++) {
      if (seq[j] >= slime.back()) continue;
      birth.push_back(seq[j]);
      seq[j] = -INF;
      birth.push_back(slime.back());
      slime.pop_back();
      cnt++;
    }
    if (!slime.empty()) {
      puts("No");
      return 0;
    }
    while (!birth.empty()) {
      slime.push_back(birth.back());
      birth.pop_back();
    }
    sort(seq.begin(), seq.end(), greater<int>());  //降順
    sort(slime.begin(), slime.end());              //昇順
    if (i != N - 1) {
      for (int j = 0; j < cnt; j++) {
        seq.pop_back();
      }
    }
  }
  puts("Yes");
  return 0;
}