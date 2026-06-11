#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  
  cin >> N;
  vector<string> S(N);
  for(int i = 0;i < N;i++) cin >> S.at(i);
  
  sort(S.begin(), S.end());
  
  int cnt = 1, cnt_max = -1;
  for(int i = 1;i < N;i++){
    if(S.at(i-1) == S.at(i)) cnt++;
    else{
      cnt_max = max(cnt_max, cnt);
      cnt = 1;
    }
  }
  cnt_max = max(cnt_max, cnt);
  cnt = 1;
  for(int i = 1;i < N;i++){
    if(S.at(i-1) == S.at(i)) cnt++;
    else{
      if(cnt == cnt_max) cout << S.at(i-1) << endl;
      cnt = 1;
    }
  }
  if(cnt == cnt_max) cout << S.at(N-1) << endl;
  
  return 0;
}