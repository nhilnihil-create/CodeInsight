//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  int n;
  cin >> n;
  long long ans = 0;
  vector<long long> F(n+1); //F[i] = f(i)

  rep2(i, 1, n+1){//one_base
    rep2(j, 1, n/i + 1){//one_base
      F[i*j] += 1;
    }
  }

  rep1(i, n+1){
    ans += i*F[i];
  }

  cout << ans;
}
