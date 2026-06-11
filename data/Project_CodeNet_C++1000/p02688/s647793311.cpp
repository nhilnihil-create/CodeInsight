#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int N, K = 0;
  cin >> N >> K;

  unordered_set<int> members;

  for (int i = 0; i < N; i++) {
    members.insert(i + 1);
  }

  int member = 0;
  int d = 0;

  for (int i = 0; i < K; i++) {
    if (members.size() == 0) {
      break;
    }
    cin >> d;
    for (int j = 0; j < d; j++) {
      if (members.size() == 0) {
        break;
      }

      cin >> member;
      members.erase(member);
    }
  }

  cout << members.size() << endl;

  return 0;
}
