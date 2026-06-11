#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string ans = "YES";
  cin >> N;
  set<string> A;
  for (int i = 0; i < N; i++){
    string a;
    cin >> a;
    A.insert(a);
  }
  if (A.size() != N){
    ans = "NO";
  }
  cout << ans << endl;
}