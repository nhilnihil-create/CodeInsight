#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int A, B;
  cin >> A >> B;
  int num = 1;
  int id = 0;
  while (num < B) {
    num--;
    id++;
    num += A;
  }
  cout << id << endl;
}