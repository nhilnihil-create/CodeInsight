#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, K, M = 0, Ans = 0;
string S;

int main(){
cin >> N >> K >> S;

if(N == 1){cout << 0;exit(0);}

rep(i, 0, N - 1){

  if(S[i] == 'R' && S[i + 1] == 'L')M++;

}

bool A = S[0] != S.back(), B = S[0] == 'R';

Ans = N - 2*M;

if(A && B){

  if(K < M)cout << Ans + 2*K;
  
  else cout << N - 1;
  
  exit(0);

}

if(A && !B){

  if(K <= M)cout << Ans - 2 + 2*K;

  else cout << N - 1;
  
  exit(0);

}

if(!A){

  if(K <= M)cout << Ans - 1 + 2*K;

  else cout << N - 1;
  
  exit(0);

}

}