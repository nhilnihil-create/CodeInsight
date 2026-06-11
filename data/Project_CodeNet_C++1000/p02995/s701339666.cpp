#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 131, task c, 2020/08/14
//ms,
/*
*/

int main(void){
  int64_t a, b, c, d;
  int64_t ans;
  int64_t c_divided, d_divided, cd_divided;
  int64_t lcm_cd;

  cin >>a >>b >>c >>d;
  ans = b-a+1;

  c_divided = b/c - a/c + 1 - min((int64_t)1, a%c);
  d_divided = b/d - a/d + 1 - min((int64_t)1, a%d);
  lcm_cd = c / gcd(c, d) * d;
  cd_divided = b/lcm_cd - a/lcm_cd + 1 - min((int64_t)1, a%lcm_cd);

  ans = ans - c_divided - d_divided + cd_divided;
  cout <<ans <<endl;
  return 0;
}
/*
余事象を使うんだ。ひっくり返す。
*/
