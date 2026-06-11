#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  vector<int> L(N);
  for(int i = 0; i < N; i++){
    cin >> L.at(i);
  }
  
  int answer = 0;
  for(int i = 0; i < N-2; i++){
    for(int j = i+1; j < N-1; j++){
      for(int k = j+1; k < N; k++){
    	if( L.at(i) != L.at(j) && L.at(j) != L.at(k) && L.at(k) != L.at(i) ){
          if ( L.at(i) + L.at(j) > L.at(k) && L.at(i) + L.at(k) > L.at(j) && L.at(j) + L.at(k) > L.at(i) ){
            answer ++;
          }
        }
      }
    }
  }
  
  cout << answer << endl;
}
