#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans=1;
  string S;
  cin >> N >> S;
  for(int i=0; i<N-1; i++){
    if(S[i] != S[i+1]){
      ans++;
    }
  }
  cout << ans << endl;
}
