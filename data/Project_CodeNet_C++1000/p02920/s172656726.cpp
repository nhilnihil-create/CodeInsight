#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main(){
  int in;
  scanf("%d", &in);
  priority_queue<int> heaven;
  for(int i = 1 << in; i; i--){
    scanf("%d", &in);
    heaven.push(in);
  }
  
  vector<int> live(1);
  live[0] = heaven.top();
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
        live.emplace_back(slime);
      }
      sort(live.begin(), live.end());
      for(int slime : unborn){
        heaven.push(slime);
      }
    }
  }
  
  puts(valid ? "Yes" : "No");
  
  return 0;
}