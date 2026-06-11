#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vi ans(n+1);
  s += 'R';
  int cntr = 0, cntl = 0;
  int tmp;
  rep(i,n+1){
    if(s[i] == 'R') {
      cntr++;
      if(s[i-1] == 'L'){
        if(cntl%2 == 0){
          ans[tmp] += cntl/2;
          ans[tmp-1] += cntl/2;
          cntl = 0;
        }
        else{
          ans[tmp] += cntl/2 + 1;
          ans[tmp-1] += cntl/2;
          cntl = 0;
        }
      }
    }
    else{
      cntl++;
      if(s[i-1] == 'R') tmp = i;
      if(cntr%2 == 0){
        ans[i] += cntr/2;
        ans[i-1] += cntr/2;
        cntr = 0;
      }
      else{
        ans[i] += cntr/2;
        ans[i-1] += cntr/2 + 1;
        cntr = 0;
      }
    }
  }
  rep(i,n) cout << ans[i] << " ";
}
