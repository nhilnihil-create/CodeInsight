#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  char alpha;
  cin >> alpha;
  if ((alpha >= 'a') && (alpha <= 'z')) {
    cout << 'a' << endl;
  } else if ((alpha >= 'A') && (alpha <= 'Z')) {
    cout << 'A' << endl;
  }
  return 0;
}