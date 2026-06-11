#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, ans=0;
  cin >> N;
  rep(i, N){
    string S;
    S = to_string(i+1);
    if (S.size()%2==1) ans++;
  }
  cout << ans << endl;
}