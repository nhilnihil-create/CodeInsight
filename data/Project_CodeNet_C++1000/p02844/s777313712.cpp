#include <bits/stdc++.h>
using namespace std;

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
int main() {
  int n;
  string S;
  cin >> n >> S;
  int ans = 0;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    s.at(i) = ctoi(S.at(i));
  }
  for(int i=0;i<10;i++){
    int a=-1;
    for(int j=0;j<n;j++){
      if(s.at(j) == i){
        a = j;
        break;
      }
    }
    if(a < 0){continue;}
    for(int j=0;j<10;j++){
      int b = -1;
      for(int k=a+1;k<n;k++){
        if(s.at(k) == j){
          b = k;
          break;
        }
      }
      if(b < 0){continue;}
      for(int k=0;k<10;k++){
        for(int l=b+1;l<n;l++){
          if(s.at(l) == k){
            ans++;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}