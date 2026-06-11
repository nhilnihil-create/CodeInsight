#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

ll N, K;

bool check(vector<ll> A, vector<ll> F, ll K, ll X){
  // X: score

  bool ret;
  ll time = 0;
  for(int i = 0; i < N; i++){
    ll tmp = A[i] * F[i];

    if(tmp <= X){
      continue;
    } else { 
      ll target = X / F[i];
      time += A[i] - target;
    }
  }
  if(time <= K) return true;
  else return false;
}


int main(){
  cout << setprecision(10);
  cin >> N >> K;
  vector<ll> A,F;
  A.assign(N,0);
  F.assign(N,0);

  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  for(int i = 0; i < N; i++){
    cin >> F.at(i);
  }
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());

  ll max_val = 0;
  for(int i = 0; i < N; i++){
    max_val = max(max_val, A.at(i) * F.at(i));
  }



  /* どんな二分探索でもここの書き方を変えずにできる！ */

  ll right = max_val;
  ll left = -1;

  while (right - left > 1) {
    ll mid = left + (right - left) / 2;

    // K回以下の修行でスコアmidを達成できるかどうか
    if(check(A,F,K,mid)){
      right = mid;
    } else {
      left = mid;
    } 
  }

  cout << right << endl;

}
