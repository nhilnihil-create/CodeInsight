#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  string S;
  cin >> N >> S;  
  int cnt = 1;
  char pre = S[0];
  for(int i=1; i<N; i++){
    if(pre==S[i]) continue;
    else{
      pre = S[i];
      cnt ++;
    }
  
  }
  
  cout << cnt << endl;
  
  
  return 0;
}