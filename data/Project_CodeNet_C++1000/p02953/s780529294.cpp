#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  rep(i, N){
    cin >> H[i];
  }
  int now = 0;
  bool flag = true;
  rep(i, N-1){
    if (H[i] - H[i+1] < 1) continue;
    if (H[i] - H[i+1] == 1){
      H[i]--;
      if (H[i] < now) flag=false;
      else now = H[i];
    }
    if (H[i] - H[i+1] > 1) flag=false;
    if (flag == false) break;
  }
  if (flag==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}