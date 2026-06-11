#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  string S[N];
  rep(i, N){
    cin >> S[i];
  }
  rep(i, N){
    sort(S[i].begin(), S[i].end());
  }
  long long ans = 0;
  unordered_map<string, long long> X;
  rep(i, N){
    X[S[i]]++;
  }
  for (auto x : X){
    long long n = x.second;
    ans += (n * (n-1) / 2);
  }
  cout << ans << endl;
}