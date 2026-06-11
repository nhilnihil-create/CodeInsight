#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  std::vector<int> WA(105000,0);
  std::vector<int> AC(105000, 0);

  int wrong = 0, correct = 0;
  rep(i,m) {
    int p;
    string s;
    cin >> p >> s;

    if (AC.at(p) == 1) continue;
    if (s == "WA") WA[p]++;
    else if (s == "AC") {
      AC.at(p) = 1;
      wrong += WA.at(p);
      correct++;
    }
  }
  cout << correct << " " << wrong << endl;
}
