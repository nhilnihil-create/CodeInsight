#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<string, int>> v(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i].first >> v[i].second;
  }
  string X; cin >> X;
  int sum = 0;
  bool sleep = false;
  for(int i = 0; i < N; i++) {
    if(sleep) sum += v[i].second;
    if(v[i].first == X) sleep = true;
  }
  cout << sum << endl;
  return 0;
}
