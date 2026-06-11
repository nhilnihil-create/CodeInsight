#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  bool flg = true;
  vector<int> H(N, 0);
  for(int i = 0; i < H.size(); i++) cin >> H[i];
  for(int i = 0; i < H.size(); i++) {
    if(i == 0) continue;
    if(H[N - i - 1] - H[N - i] == 1) H[N - i - 1]--;
    else if(H[N - i - 1] - H[N - i] > 1) { flg = false; break; }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}