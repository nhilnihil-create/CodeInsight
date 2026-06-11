#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &a, int g, int &cnt) {
  int N = a.size();
  for (int i = g; i < N; ++i) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      ++cnt;
    }
    a[j + g] = v;
  }
}

void shell_sort(vector<int> &a) {
  int n = a.size();
  vector<int> g;
  while (n) {
    g.push_back(n);
    n /= 2;
  }

  int cnt = 0;
  int m = g.size();
  for (int i = 0; i < m; ++i) {
    insertion_sort(a, g[i], cnt);
  }

  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    if (i) cout << " ";
    cout << g[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (auto t : a) {
    cout << t << endl;
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> a;
  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    a.push_back(t);
  }

  shell_sort(a);
}