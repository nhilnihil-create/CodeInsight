#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  bool ans=1;
  cin >> S;

  for(int i=0;i<3;i++){
    if(S[i]==S[i+1])ans=0;
  }

  if(ans)cout << "Good" << endl;
  else cout << "Bad" << endl;
}
