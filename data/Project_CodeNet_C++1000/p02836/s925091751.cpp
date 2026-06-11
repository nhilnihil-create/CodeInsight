#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  int half;
  if (S.size() % 2 == 0){
    half = S.size() / 2;
  }
  else
  {
    half = (S.size() - 1) / 2;
  }
  
  int cnt = 0;
  for (int i = 0; i < half; i++){
    if (S.at(i) != S.at(S.size() - 1 - i )) cnt += 1;
  }

  cout << cnt << endl;
}