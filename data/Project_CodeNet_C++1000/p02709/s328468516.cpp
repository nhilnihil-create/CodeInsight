#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<int> idx(N);
  iota(idx.begin(), idx.end(), 0);

  auto comp= [&](int i, int j){
    return data.at(i) > data.at(j);
  };
  sort(idx.begin(), idx.end(), comp);

  vector<int64_t> dp(N+1);
  vector<int64_t> buf(N+1);
  for(int n_perm=1; n_perm<= N; n_perm++){
    int i0= idx.at(n_perm-1);
    int64_t a0= data.at(i0);
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