#include <bits/stdc++.h>
#include <vector>
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
  if(days > N){std::cout << "-1" << std::endl;}
  
  else{
      std::cout << N - days << std::endl;
  }
  
}

