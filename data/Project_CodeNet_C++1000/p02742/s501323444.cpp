#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t h,w;
  cin >> h >> w;
  int64_t case1 = 0;
  int64_t case2 = 0;
  int64_t answer = 0;
  if(h == 1 || w == 1)
    answer = 1;
  else if(w % 2 == 0 && h % 2 == 0){
    case1 = w / 2;
    case2 = case1;
    for(int i=0;i<h/2;i++){
      answer += case1 +case2;
    }
  }
  else if(w % 2 == 0 && h % 2 == 1){
    case1 = w / 2;
    case2 = case1;
    for(int i=0;i<(h-1)/2;i++){
      answer += case1 + case2;
    }
    answer += case1;
  }
  else if(w % 2 == 1 && h % 2 == 0){
    case1 = (w+1)/2;
    case2 = case1 - 1;
    for(int i=0;i<h/2;i++){
      answer += case1 +case2;
    }
  }
  else if(w % 2 == 1 && h % 2 == 1){
    case1 = (w+1)/2;
    case2 = case1 - 1;
    for(int i=0;i<(h-1)/2;i++){
      answer += case1 + case2;
    }
    answer += case1;
  }
  
  
  
  
  cout << answer << endl;
    
}
