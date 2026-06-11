#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  queue<int> ans;
  int cnt = 0;
  int r_cnt = 0;

  rep(i, N){
    cnt++;
    if(S[i] == 'R') r_cnt++;
    if(S[i]=='L' && S[i+1]=='R'){
      //cout << cnt << endl;
      if(cnt % 2 == 0){
        ans.push(cnt/2);
        ans.push(cnt/2);
      }
      else{
        if(r_cnt%2){
          ans.push((cnt+1)/2);
          ans.push((cnt-1)/2);
        }
        else{
          ans.push((cnt-1)/2);
          ans.push((cnt+1)/2);
        }

      }
      cnt = 0;
      r_cnt = 0;
    }
  }

  if(cnt % 2 == 0){
    ans.push(cnt/2);
    ans.push(cnt/2);
  }
  else{
    if(r_cnt%2){
      ans.push((cnt+1)/2);
      ans.push((cnt-1)/2);
    }
    else{
      ans.push((cnt-1)/2);
      ans.push((cnt+1)/2);
    }

  }

  rep(i, N){
    if(S[i]=='R' && S[i+1]=='L'){
      cout << ans.front() << endl;
      ans.pop();
      i++;
      cout << ans.front() << endl;
      ans.pop();
    }
    else cout << 0 << endl;
  }

}
