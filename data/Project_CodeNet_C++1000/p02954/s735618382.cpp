#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int N = (int)(S.length());
  
  char prev = 'R';
  vector<int> ans(N, 0);
  int kid = 0, gat = 0;
  
  for (int i = 0; i < N; i++){
    if (prev == 'R' && S.at(i) == 'L'){
      gat = i - 1;
      int Rget = kid / 2;
      ans.at(gat) += Rget + 1;
      ans.at(gat + 1) += kid - Rget + 1;
      kid = 0;
    }
    else if (S.at(i) == 'L'){
      if ((i - gat) % 2 == 1){
        ans.at(gat + 1)++;
      }
      else{
        ans.at(gat)++;
      }
    }
    else if (S.at(i) == 'R' && S.at(i + 1) == 'R'){
      kid++;
    }
    
    prev = S.at(i);
  }
  
  for (int i = 0; i < N; i++){
    cout << ans.at(i) << ' ';
  }
  cout << endl;


}