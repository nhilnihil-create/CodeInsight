#include<iostream>
#include<list>
#include<stack>
using namespace std;

int main() {
  int N, Q; cin >> N >> Q;
  list<int> E[N];
  int a, b, p, x;
  long counter[N]; for (int i = 0; i < N; i++) counter[i] = 0;
  for (int i = 0; i < N-1; i++) {
    cin >> a >> b; a--; b--;
    E[a].push_back(b); E[b].push_back(a);
  }
  for (int q = 0; q < Q; q++) {
    cin >> p >> x; p--;
    counter[p] += x;
  }
  bool visited[N]; for (int i = 0; i < N; i++) visited[i] = false;
  visited[0] = true;
  stack<int> S; S.push(0);
  while (!S.empty()) {
    int u = S.top(); S.pop();
    for (auto it = E[u].begin(); it != E[u].end(); it++) {
      if (!visited[*it]) {
        visited[*it] = true;
        counter[*it] += counter[u];
        S.push(*it);
      }
    }
  }
  for (int i = 0; i < N; i++) cout << counter[i] << endl;
}