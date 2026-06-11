#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  vector<bool> snuke(N);
  
  int A;
  vector<int> d(K);
  for(int i = 0; i < K; i++){
    cin >> d.at(i);
    for(int j = 0; j < d.at(i); j++){
      cin >> A;
      snuke.at(A-1) = true;
    }
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
	if(snuke.at(i) == false){
      ans++;
    }
  }
  cout << ans << endl;

}