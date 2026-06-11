#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int64_t INF= 1e18;
  int N;
  cin >> N;

  vector<int64_t> data(N+1);
  for(int d=0; d<=N; d++){
    cin >> data.at(d);
  }

  vector<int64_t> bottomup(N+1);
  bottomup.at(N)= data.at(N);
  for(int d=N; d>0; d--){
    bottomup.at(d-1)= data.at(d-1)+ bottomup.at(d);
  }
  
  int64_t cnt= 0;
  int64_t topdown= 1;
  bool has_overflowed= false;
  bool is_satisfied= true;
  for(int d=0; d<=N; d++){
    int64_t cnt_d= min(topdown, bottomup.at(d));
    if(cnt_d < data.at(d)){
      is_satisfied= false;
      break;
    }
    else{
      cnt+= cnt_d;

      topdown= !has_overflowed ? 2*(topdown- data.at(d))
                               : INF;
      has_overflowed= (topdown >= INF);
    }
  }

  int64_t ans= is_satisfied ? cnt
                            : -1;
  cout << ans << endl;
}