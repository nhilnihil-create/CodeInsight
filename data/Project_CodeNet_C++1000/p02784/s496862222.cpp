#include <bits/stdc++.h>
using namespace std;

int main(){
  long long H, N;
  cin >> H >> N;
  vector<long long> atk(N);
  for (int i = 0; i < N; i++){
    cin >> atk.at(i);
  }
  
  long long ATK = 0;
  
  for (int i = 0; i < N; i++){
    ATK += atk.at(i);
  }
  
  if (ATK >= H){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    
