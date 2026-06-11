#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
  char c;
  int odd;
  int even;
  int used;
};

void hoge(vector<node> &vec, int c, int last = -1) {
  int next = vec[c].c == 'R' ? c + 1 : c - 1;
  if (vec[next].used == 1) {
    vec[c].even = vec[next].odd;
    vec[c].odd = vec[next].even;
    vec[c].used = true;
  }
  else if (next == last) {
    vec[c].even = c;
    vec[c].odd = next;
    vec[c].used = true;
  }
  else {
    hoge(vec, next, c);
    vec[c].even = vec[next].odd;
    vec[c].odd = vec[next].even;
    vec[c].used = true;
  }
}

int main() {
  vector<node> vec;
  char c;
  while (cin >> c)
    vec.push_back({c, 0, 0, 0});

  for (int i = 0; i < static_cast<int>(vec.size()); ++i)
    hoge(vec, i);

  vector<int> ans(static_cast<int>(vec.size()), 0);
  for (int i = 0; i < static_cast<int>(vec.size()); ++i)
    ++ans[vec[i].even];

  cout << ans[0];
  for (int i = 1; i < static_cast<int>(ans.size()); ++i)
    cout << " " << ans[i];
  cout << endl;
}