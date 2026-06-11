#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
  int N;
  string S;
  map<string, int> cnt;
  
  cin >> N;
  int cnt_max = 0;
  for(int i = 0;i < N;i++){
    cin >> S;
    cnt_max = max(cnt_max, ++cnt[S]);
  }
  
  for(auto itr = cnt.begin();itr != cnt.end(); itr++){
    if(itr->second == cnt_max) cout << itr->first << endl;
  }
  
  return 0;
}