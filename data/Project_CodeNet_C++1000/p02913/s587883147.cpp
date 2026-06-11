#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  int N,i,j,c,ans = 0;string s;cin >> N >> s;
  //i文字ずらして,i文字以下揃っているならばansにカウント
  for(i=1;i<N;i++){
    c = 0;//連続して揃っている文字数カウント
    for(j=0;j+i<N;j++){
      if(s[j] == s[j+i]){
        c++;
        if(c <= i){
          ans = max(ans,c);
        }
      } else c = 0;
    }
  }
  cout << ans << "\n";
}