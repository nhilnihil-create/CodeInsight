#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  int max = A.at(0);
  long long humidai = 0;
  
  for(int i = 1; i < N; i++){
    if(A.at(i) < max){
      humidai += (max - A.at(i));
    }else{
      max = A.at(i);
    }
  }
  
  cout << humidai << endl;
}
