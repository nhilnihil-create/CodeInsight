#include <iostream>
#include <atcoder/dsu>

using namespace std;

int main() {
  int N, M, A, B;
  cin >> N >> M;
  atcoder::dsu d(N);
  while(cin >> A >> B) d.merge(--A, --B);
  cout << d.groups().size() - 1 << endl;
}
