#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int days = 0 ;
  
  for (int i = 0; i < N; i++) {
      int take_days = 0;
      cin >> take_days;
      days += take_days;
    
  }
  if(days > N){cout << "-1" << endl;}
  
  else{
      std::cout << N - days << endl;
  }
  
}

