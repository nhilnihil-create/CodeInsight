//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int n;
  cin >> n;
  long long ans = 0;
  vector<int> A(n);
  rep1(i, n){
    cin >> A[i];
  }
  int tem = A[0];
  rep1(i, n){
    if(tem < A[i]){
      tem = A[i];
    }
    else{
      ans += tem - A[i];
    }
  }
  cout << ans;
}