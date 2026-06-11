#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  map<string,int> mp;
  for(int i=0;i<N;i++){
    cin >> S;
    mp[S] ++;
  }
  
  int val_max = 0;
  for(auto itr=mp.begin();itr != mp.end();itr++){
    if(itr->second > val_max ) val_max = itr->second;
  }
  
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    if(itr->second == val_max){
      cout << itr->first << endl;
    }
  }
}