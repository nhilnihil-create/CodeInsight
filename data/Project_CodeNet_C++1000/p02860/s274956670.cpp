#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  string S;
  cin >> N >> S;

  /*
  string ans = "Yes";
  if (S.size() % 2 == 1) cout << "No" << endl;
  else{
    for(int i = 0; i <= N / 2 - 1; i++){
      if (S.at(i) != S.at(i + N / 2)){
        ans = "No";
        break;
      }
    }
  }
  cout << ans << endl;
  */
  string ans = "No";
  int K = N / 2;
  if (N % 2 == 0 && S.substr(0, K) == S.substr(K, K)) ans =  "Yes";
  cout << ans << endl;
}
