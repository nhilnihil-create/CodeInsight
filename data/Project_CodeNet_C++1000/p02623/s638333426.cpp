#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, M, K, sum = 0, Ans = 0;

int main(){
cin >> N >> M >> K;
vector<ll> A(N + 1);
vector<ll> B(M + 1);

rep(i, 1, N + 1){
  
  ll a;cin >> a;

  sum += a;A[i] = sum;

}

sum = 0;

rep(i, 1, M + 1){
  
  ll b;cin >> b;

  sum += b;B[i] = sum;

}

rep(i, 0, N + 1){
  
  if(A[i] > K)break;

  auto I = upper_bound(ALL(B), K - A[i]);

  ll j = I - B.begin() - 1;

  Ans = max(i + j, Ans);

}

cout << Ans;

}