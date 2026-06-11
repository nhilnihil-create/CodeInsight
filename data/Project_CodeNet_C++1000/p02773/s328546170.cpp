#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  map<string, int> list;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    list[S] += 1;
  }
  int max = 0;
  for (const auto& x : list) {
    if (max < x.second) {
      int v = x.second;
      max = v;
    }
  }
  for (auto itr = list.begin(); itr != list.end(); itr++) {
    if (itr->second == max) {
      cout << itr->first << endl;
    }
  }
}