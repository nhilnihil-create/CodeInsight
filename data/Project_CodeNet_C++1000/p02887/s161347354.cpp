#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()

int main(){
  int N; cin >> N;
  string S; cin >> S;
  S.erase(unique(ALL(S)),S.end());
  cout << S.size() << endl;
  return 0;
}
