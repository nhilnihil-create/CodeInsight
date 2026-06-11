#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, c=0;
  string ans = "YES";
  cin >> N;
  vector<string> A(N);
  for (int i; i < N; i++){
    cin >> A.at(i);
  }
  set<string> B;
  while (c < N){
    if (B.count(A.at(c)) == 1){
      ans = "NO";
      break;
    }
    B.insert(A.at(c));
    c++;
  }
  cout << ans << endl;
}