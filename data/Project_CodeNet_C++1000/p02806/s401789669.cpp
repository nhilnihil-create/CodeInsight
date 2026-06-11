#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans=0;
  cin >> N;
  vector<string>s(N);
  vector<int>t(N);
  for(int i=0; i<N; i++){
    cin >> s[i] >> t[i];
  }
  string X;
  cin >> X;
  for(int i=0; i<N; i++){
    if(s[i] == X){
      for(int j=i+1; j<N; j++){
        ans += t[j];
      }
      cout << ans << endl;
      return 0;
    }
  }
}
