#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int all = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    all = all ^ A.at(i);
  }
  
  vector<int> ans(N);
  for (int i = 0; i < N; i++){
    ans.at(i) = all ^ A.at(i);
  }
  
  for (int i = 0; i < N; i++){
    cout << ans.at(i) << " ";
  }
  cout << endl;
}