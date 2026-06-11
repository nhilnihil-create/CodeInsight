#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  string S;
  cin >> K >> S;
  
  int n;
  n = S.size();
  
  if(n <= K)
    cout << S << endl;
  
  else{
    S.erase(K);
    cout << S << "..." << endl;
  }
}
