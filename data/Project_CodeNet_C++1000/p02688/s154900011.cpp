#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> v(N, 0);
  for(int i = 0; i < K; i++) {
    int d;
    cin >> d;
    for(int j = 0; j < d; j++) {
      int n;
      cin >> n;
      v[n-1]++;
    }
  }
  int ans = 0;
  for(const auto& e: v) {
    if(e==0) ans++;
  }
  
  cout << ans << endl;
 return 0; 
}