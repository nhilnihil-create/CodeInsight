#include <iostream>
using namespace std;

int main() {
  int N, M;
  long long workNum = 0;
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int l;
    cin >> l;
    workNum+=l;
  }
  cout << (N < workNum ? -1 : N - workNum) << endl;
  return 0;
}