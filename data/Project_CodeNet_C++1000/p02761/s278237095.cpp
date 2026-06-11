#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int N,M;
  cin >> N >> M;
  int s[M],c[M];
  rep(i,M) cin >> s[i] >> c[i];
  int ans = 0;
  if(N!=1) ans = pow(10,N-1);
  int ans_max = pow(10,N);
  bool correct = true;
  int i;
  for(i=ans;i<ans_max;i++){
    correct = true;
    string ans_2 = to_string(i);
    rep(j,M){
      string c_2 = to_string(c[j]);
      if(ans_2[s[j]-1]!=c_2[0]){
        correct = false;
      }
    }
    if(correct) break;
  }
  if(correct) printf("%d",i);
  else printf("%d", -1);
}