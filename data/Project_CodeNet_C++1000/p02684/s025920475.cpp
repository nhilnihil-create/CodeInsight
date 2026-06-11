#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll N, K, p = 0;cin >> N >> K;
vector<ll> A(N);
map<ll, ll> M;

rep(i, 0, N)cin >> A[i];

M[1] = 1;

rep(i, 2, K + 2){

  if(M[A[p]] == 0){
  
    M[A[p]] = i;

    if(i < K + 1)p = A[p] - 1;

  }

  else{

    ll L = i - M[A[p]], C = (K - M[A[p]] + 1)/L;

    i += L*(C - 1);

    M.clear();
    
    if(i != K + 1)p = A[p] - 1;

  }

}

cout << A[p];

}