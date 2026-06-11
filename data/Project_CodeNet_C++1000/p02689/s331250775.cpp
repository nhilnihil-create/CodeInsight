#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  vector<int> map(N);
  for(int i = 0; i < N; i++) {
    cin >> H[i];
    map[i] = H[i];
  }
  
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    map[A] = max(map[A], H[B]+1);
    map[B] = max(map[B], H[A]+1);
  }
  
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(map[i]==H[i]) ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}