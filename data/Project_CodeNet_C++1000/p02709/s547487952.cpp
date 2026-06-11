#include <bits/stdc++.h>
using namespace std;

int main(){
  using infant= pair<int64_t, int>;
  int N;
  cin >> N;
  
  priority_queue<infant> data;
  int64_t val;
  for(int i=0; i<N; i++){
    cin >> val;
    data.push(make_pair(val, i));
  }

  vector<int64_t> dp(N+1);
  vector<int64_t> buf(N+1);
  for(int n_perm=1; n_perm<= N; n_perm++){
    auto infant_tmp= data.top();
    data.pop();
    int64_t a0; int i0;
    tie(a0, i0)= infant_tmp;
    for(int n_left=0; n_left <= n_perm; n_left++){
      int n_right= n_perm- n_left;
      int i_left = n_left- 1;
      int i_right= N- n_right;

      buf.at(n_left)= (n_left ==0) ? dp.at(n_left)+ a0* abs(i_right- i0)
                     :(n_right==0) ? dp.at(n_left- 1)+ a0* abs(i_left- i0)
                                   : max(dp.at(n_left)+ a0* abs(i_right- i0), dp.at(n_left- 1)+ a0* abs(i_left- i0));
    }

    dp= buf;
  }

  int64_t ans= 0;
  for(auto elem:dp){
    ans= max(ans, elem);
  }

  cout << ans << endl;
}