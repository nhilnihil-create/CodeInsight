#include<bits/stdc++.h>
using namespace std;

int main(){
  string S0, S1;
  cin >> S0;
  long long int N = S0.size();
  bool f1, f2;
  f1 = f2 = false;
  
  S1 = S0;
  reverse(S1.begin(), S1.end());
  if(S0 == S1) f1 = true;
  
  if(S0.substr(0, (N - 1) / 2) == S1.substr((N + 3) / 2 - 1)) f2 = true;
  
  if(f1 && f2) cout << "Yes" << endl;
  else cout << "No" << endl;
}
