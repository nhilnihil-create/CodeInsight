#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int K;
  string S;
  cin >> K >> S;

  if (K >= S.size()) cout << S << endl;
  else{
    rep(i,K){
      cout << S.at(i);
    }
    cout << "..." << endl;
  }
}
