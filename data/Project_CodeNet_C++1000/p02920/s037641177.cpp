#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int power2(int e){
  if(e == 0) return 1;
  else if(e & 1) return 2 * power2(e - 1);
  else{
    int p = power2(e >> 1);
    return p * p;
  }
}

int main(){
  int N;
  cin >> N;
  int er_N = power2(N);
  priority_queue<int> heaven;
  for(int i = 0; i < er_N; i++){
    int S;
    cin >> S;
    heaven.push(S);
  }
  
  multiset<int> live;
  live.insert(heaven.top());
  heaven.pop();
  
  bool valid = true;
  while(valid && !heaven.empty()){
    multiset<int> unborn;
    multiset<int> born;
    for(auto itr = live.rbegin(); itr != live.rend(); itr++){
      int slime = INF;
      while(!heaven.empty()){
        slime = heaven.top();
        heaven.pop();
        if(slime >= *itr){
          unborn.insert(slime);
        }else break;
      }
      if(slime < *itr){
        born.insert(slime);
      }else{
        valid = false;
        break;
      }
    }
    
    if(valid){
      for(int slime : born){
        live.insert(slime);
      }
      for(int slime : unborn){
        heaven.push(slime);
      }
    }
  }
  
  cout << (valid ? "Yes" : "No") << endl;
  
  return 0;
}