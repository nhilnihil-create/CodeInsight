#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N=0, L=0, cnt=0, ans_sum=0;

int main(){
  cin >> N >> L;
  rep(i, N){
    ans_sum += L + cnt;
    cnt ++;
  }
  if (L > 0) cout << ans_sum - L << endl;
  else if(L + N - 1 < 0) cout << ans_sum - (L + N - 1) << endl;
  else cout << ans_sum << endl;
}