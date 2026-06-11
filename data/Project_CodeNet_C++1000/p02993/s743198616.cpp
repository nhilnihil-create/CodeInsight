#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  rep(i, S.size() - 1){
      if (S.at(i) == S.at(i + 1)){
        cout << "Bad" << endl;
        return 0;
      }
  }
  cout << "Good" << endl;
}