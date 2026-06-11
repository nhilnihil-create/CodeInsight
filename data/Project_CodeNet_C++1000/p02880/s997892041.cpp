#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
  int n;
  bool finished = false;
  cin >> n;
  vector<vector<int>> a(9, vector<int>(9));
  rep(i, 9){
    if(finished) break;
    rep(j, 9){
      a.at(i).at(j) = (i + 1) * (j + 1);
      if(a.at(i).at(j) == n){
        cout << "Yes" << endl;
        finished = true;
        break;
      }
    }   
  }
  if(!(finished)) 
    cout << "No" << endl;
}