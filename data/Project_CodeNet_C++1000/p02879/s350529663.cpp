#include <bits/stdc++.h> 
using namespace std;

int main() {
  int N;
  int S;
  cin >> N >> S;
  if (N > 9 || S > 9)
    cout << -1 << endl;
  else
    cout << N*S << endl;
    
}
