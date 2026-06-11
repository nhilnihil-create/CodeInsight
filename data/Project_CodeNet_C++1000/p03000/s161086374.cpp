#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N=0, X=0, l=0, acc=0, ans=0;

int main(){
  cin >> N >> X;
  rep(i, N){
    cin >> l;
    acc += l;
    if (acc <= X) ans ++;
    else break;
  }
  cout << ans + 1 << endl;
}