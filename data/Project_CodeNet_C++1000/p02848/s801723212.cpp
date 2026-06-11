#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  string S;
  cin >>  N >> S;

  rep(i,S.size()){
      int index = S.at(i) - 'A';  //S[i]がアルファベット何番目か（0-indexed)
      index = (index + N) % 26;
      cout << char(index + 'A');
  }
  cout << endl;
}
