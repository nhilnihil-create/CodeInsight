#include <atcoder/dsu>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  atcoder::dsu towns(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    towns.merge(A, B);
  }
  int answer = towns.groups().size() - 1;
  cout << answer << endl;
  return 0;
}
