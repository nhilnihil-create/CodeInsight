#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef pair<char, int> P;

void myprint(vector<P> &a) {
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (it != a.begin()) {
      cout << " ";
    }
    cout << it->first << it->second;
  }
  cout << endl;
}

void check_stable(vector<P> &a, vector<P> &b) {
  map<P, int> m;
  for (int i = 0; i < a.size(); ++i) {
    m[a[i]] = i;
  }

  int p = -1;
  int q = -1;
  bool stable = true;
  for (int i = 0; i < b.size(); ++i) {
    if (p != b[i].second) {
      p = b[i].second;
      q = m[b[i]];
      continue;
    }
    if (m[b[i]] < q) {
      stable = false;
      break;
    }
    q = m[b[i]];
  }

  if (stable) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
}

void bubble_sort(vector<P> &a) {
  vector<P> c;

  int N = a.size();
  c.resize(N);
  copy(a.begin(), a.end(), c.begin());

  for (int i = 0; i < N; ++i) {
    for (int j = N - 1; j >= i + 1; --j){
      if(c[j].second < c[j - 1].second) {
        P t = c[j];
        c[j] = c[j - 1];
        c[j - 1] = t;
      }
    }
  }

  myprint(c);
  check_stable(a, c);
}

bool selection_sort(vector<P> &a) {
  vector<P> c;

  int N = a.size();
  c.resize(N);
  copy(a.begin(), a.end(), c.begin());

  for (int i = 0; i < N; ++i) {
    int m = i;
    for (int j = i; j < N; ++j) {
      if(c[j].second < c[m].second) {
        m = j;
      }
    }
    if (m != i) {
      P t = c[i];
      c[i] = c[m];
      c[m] = t;
    }
  }

  myprint(c);
  check_stable(a, c);
}

int main() {
  int N;
  cin >> N;

  vector<P> a;
  for (int i = 0; i < N; ++i) {
    string t;
    cin >> t;
    a.push_back(P(t[0], t[1] - '0'));
  }

  bubble_sort(a);
  selection_sort(a);

  return 0;
}