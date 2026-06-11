#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<ll> B(N);
  for(int i = 0; i < N; i++) cin >> B[i];

  vector<ll> back(N);
  for(int i = 0; i < N; i++){
    back[B[i]-1]++;
  }

  vector<ll> A;
  for(int i = 0; i < N; i++){
    if(back[i] > 0){
      A.push_back(back[i]);
    }
  }

  sort(A.begin(), A.end());

  int M = A.size();

  vector<ll> sumA(M+1);
  sumA[0] = 0;
  for(int i = 0; i < M; i++){
    sumA[i+1] = sumA[i] + A[i];
  }

  vector<ll> ans(N+1);
  for(int i = 0; i < N+1; i++) ans[i] = 0LL;

  for(int k = 1; k <= N; k++){

    if(k > M) continue;

    int left = 0;
    int right = k;


    while(right - left > 1){

      int l = left + (right - left) / 2;

      ll amount = sumA[M-l];
      ll cnt = amount / (k - l);

      if(A[M-l] >= cnt){ //残せる
        left = l;
      }else{
        right = l;
      }
    }

    // leftがギリギリ

    ll amount = sumA[M-left];
    ll T = M - left;
    ans[k] = amount / (k - left);

  }

  for(int k = 1; k <= N; k++){
    cout << ans[k] << endl;
  }


  return 0;
}
