#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;

  string ans= (500*N >= X) ? "Yes"
                           : "No";
  
  cout << ans << endl;
}