#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int>p(M);
  vector<string>S(M);
  for (int i = 0; i < M; i++) {
    cin >> p.at(i) >> S.at(i);
  }
  vector<int>AC(N,-1);
  for (int i = M-1; i >= 0; i--) {
    if (S.at(i) == "AC"){
      AC.at(p.at(i)-1) = i;
    }
  }
  int ACcount = 0;
  for (int i = 0; i < N; i++) {
    if (AC.at(i) != -1){
      ACcount++;
    }
  }
  
  int WAcount = 0;
  for (int i = 0; i < M; i++) {
    if (AC.at(p.at(i)-1) != -1 && AC.at(p.at(i)-1) > i){
      WAcount++;
    }
  }
  cout << ACcount << ' ' << WAcount << endl;
}
  

