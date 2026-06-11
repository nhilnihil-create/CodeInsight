#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)




int main(){
  string S;
  int N;
  cin >> N >> S;

  char c = '0';
  for (int i = 0; i < S.size(); i++){
    if ((char)(S.at(i) + N) > 'Z'){
      c = (char)(S.at(i) + N - 26);
    }
    else
    {
      c = (char)(S.at(i) + N);
    }
    string C = {c};
    S = S.replace(i, 1, C);
  }

  cout << S << endl;
}