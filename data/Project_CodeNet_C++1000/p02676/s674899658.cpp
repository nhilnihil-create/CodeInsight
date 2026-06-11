#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int K;
  string S;
  cin >> K >> S;

  for (int i = 0; i < S.size(); i++){
    if (i > K - 1){
      cout << "..." << endl;
      return 0;
    }
    else
    {
      cout << S.at(i);
    }
    
  }
  if (S.size() <= K) cout << "" << endl;
}
