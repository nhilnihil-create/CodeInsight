#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll N;
  cin >> N;
  vector<ll>B(N+2);
  vector<ll>A(N+1);
  
  ll ans = 0;
  rep(i,N+1)cin >> A[i];
  rep(i,N)cin >> B[i];
  
  for(int i = 0; i < N; i++){
    if(A[i] >= B[i])ans += B[i]; //B[i]だけ倒して町にはモンスターが残る
    else if(A[i] < B[i]){
      ans += A[i];//町にいるモンスターは全滅
      B[i] -= A[i]; //倒せる残りの数を更新
      if(A[i+1] >= B[i]){ //次の街にいるモンスターのほうがキャパより多い
        ans += B[i];
        A[i+1] -= B[i];
      }
      else if(A[i+1] < B[i]){ //次の街も全滅させられる
        ans += A[i+1];
        A[i+1] = 0;
      }
    }
  }
  cout << ans << endl;
}