#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<string>S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
    sort(S.at(i).begin(), S.at(i).end());
  }
  
  sort(S.begin(), S.end());
  
  long long counta = 1;
  long long countb = 0;
  for (int i = 0; i < N-1; i++) {
    if (S.at(i) == S.at(i+1)){
      counta++;
    }
    if (S.at(i) != S.at(i+1) || i == N-2){
      countb += counta * (counta-1) / 2;
      counta = 1;
    }
  }
  cout << countb << endl;
}
  
  
    