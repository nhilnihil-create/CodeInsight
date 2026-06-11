#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,sum=0; cin >> N;
  vector<string> s(N+10);
  vector<int> t(N+10);
  
  for(int i=1; i<=N; i++) cin >> s[i] >> t[i];
  
  string X; cin >> X;
  for(int i=1; i<=N; i++) {
    if(s[i] == X) {
      for(int j=i+1; j<=N; j++) sum += t[j];
    }
  }
  cout << sum << endl;
}