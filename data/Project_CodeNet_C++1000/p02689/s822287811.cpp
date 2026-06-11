#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  
  int A, B;
  vector<bool> good(N);
  for(int i = 0; i < N; i++){
    good.at(i) = true;
  }
    
  for(int i = 0; i < M; i++){
    cin >> A >> B;
    if(H.at(A-1) <= H.at(B-1)){
      good.at(A-1) = false;
//      cout << A << B << " Aです" << endl;
    }
    if(H.at(A-1) >= H.at(B-1)){
      good.at(B-1) = false;
//      cout << A << B << " Bです" << endl;
    }
  }
  
  int ans = 0;
  for(int i = 0; i < N; i++){
//    cout << good.at(i) << endl;
	if(good.at(i) == true){
      ans++;
    }
  }
  cout << ans << endl;

}