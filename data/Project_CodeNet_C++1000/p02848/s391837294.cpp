#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  char c;
  rep(i,S.size()){
    if(S[i]+N<='Z') c = S[i]+N;
    else c = S[i]+N-'Z'+'A'-1;
    cout << c;
  }
  cout << endl;
  return 0;
}
