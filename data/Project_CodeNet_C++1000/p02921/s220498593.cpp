#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N;
  string S, T;
  cin >> S >> T;
  int ans = 0;
  if(S[0] == T[0]) ans++;
  if(S[1] == T[1]) ans++;
  if(S[2] == T[2]) ans++;
  cout << ans << endl;
}
