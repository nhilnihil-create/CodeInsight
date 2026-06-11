#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main(){
  int in;
  scanf("%d", &in);
  int er_N = 1 << in;
  priority_queue<int> heaven;
  for(int i = 0; i < er_N; i++){
    scanf("%d", &in);
    heaven.push(in);
  }
  
  multiset<int> live;
  live.insert(heaven.top());
  heaven.pop();
  
  bool valid = true;
  while(valid && !heaven.empty()){
    vector<int> unborn;
    vector<int> born;
    for(auto itr = live.rbegin(); itr != live.rend(); itr++){
      int slime = INF;
      while(!heaven.empty()){
        slime = heaven.top();
        heaven.pop();
        if(slime >= *itr){
          unborn.emplace_back(slime);
        }else break;
      }
      if(slime < *itr){
        born.emplace_back(slime);
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
  
  puts(valid ? "Yes" : "No");
  
  return 0;
}