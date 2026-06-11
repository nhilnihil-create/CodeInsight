#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  int A[20];
  int X[20][20];
  int Y[20][20];
  cin >> N;
  rep(i, N){
    cin >> A[i];
    rep(j, A[i]){
      cin >> X[i][j];
      X[i][j]--;
      cin >> Y[i][j];
    }
  }

  int ans = 0;
  rep(mask, 1<<N){
    bool flag[N];
    rep(n, N){
      if (mask & (1<<n)) flag[n]=true;
      else flag[n]=false;
    }

    bool check = true;
    int sums = 0;
    rep(i, N){
      if (flag[i]==false) continue;
      rep(j, A[i]){
        if (Y[i][j] != flag[X[i][j]]) check = false;
      }
    }
    if (check == true){
      rep(i, N) sums += flag[i];
      ans = max(ans, sums);
    }
  }
  cout << ans << endl;
}