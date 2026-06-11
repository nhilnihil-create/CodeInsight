#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int WA[N+1];
  bool AC[N+1];
  rep(i, N+1){
    AC[i] = false;
    WA[i] = 0;
  }
  rep(i, M){
    int p;
    string s;
    cin >> p >> s;
    if (AC[p]==true) continue;
    else if (s=="AC"){
      AC[p] = true;
    }
    else WA[p]++;
  }
  int sum_wa = 0;
  int sum_ac = 0;
  rep(i, N+1){
    if (AC[i]) sum_wa += WA[i];
    sum_ac += AC[i];
  }
  cout << sum_ac << " " << sum_wa << endl;
}
