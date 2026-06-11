//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  int n ,k;
  cin >> n >> k;
  vector<long long> H(n);
  rep(i, 0, n){
    cin >> H[i];
  }
  rep(i, 0, n){
    
  }
  sort(H.begin(), H.end());
  rep(i, 0, k){
    if(!H.empty())H.pop_back();
  }
  H.push_back(0);
  cout << accumulate(H.begin(), H.end(), 0LL);

}