#include <iostream>
using namespace std;

#define ll long long int

ll max(ll a, ll b){
  if(a > b) return a;
  return b;
}

ll min(ll a, ll b){
  if(a < b) return a;
  return b;
}

ll Solve(int N, int R, int S, ll* H, ll* Kai){
  //cout << "Solve: " << R << " " << S << endl;
  ll ret = LLONG_MAX>>2;
  if(R <= 0){
    ret = 0;
  }else if(S == 1){
    ret = H[R];
  }else if(Kai[(N+1)*R+S] >= 0){
    //cout << "sanshou"<< endl;
    ret = Kai[(N+1)*R+S];
  }else{
    for(int i = S-1; i < R; ++i){
      ll tmp = Solve(N, i, S-1, H, Kai) + max(0, H[R] - H[i]);
      //cout << "tmp " << i << " " << (S-1) << " " << tmp << " " << ret << endl;
      ret = min(ret, tmp);
      //cout << "tmp " << i << " " << (S-1) << " " << tmp << " " << ret << endl;
    }
    Kai[(N+1)*R+S] = ret;
  }
  //cout << R << " " << S << " " << ret << endl;
  return ret;
}

int main(){
  int N, K;
  cin >> N >> K;
  ll H[N+1];
  H[0] = 0;
  for(int i = 0; i < N; ++i) cin >> H[i+1];
  ll Kai[(N+1)*(N+1)];
  for(int i = 0; i < (N+1)*(N+1); ++i) Kai[i] = -1;

  //cout << N << " " << K << endl;
  //for(int i = 0; i < N+1; ++i) cout << " " << H[i];
  //cout << endl;
  ll ret = LLONG_MAX >> 2;
  for(int i = N-K; i <= N; ++i){
    ll tmp = Solve(N, i, N-K, H, Kai);
    ret = min(ret, tmp);
  }
  cout << ret << endl;

  return 0;
}
