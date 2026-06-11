#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;
vector<ll> A(N + 1);
vector<bool> B(N + 1);

rep(i, 1, N + 1){
  
  cin >> A[i];

  if(i >= N/2 + 1){
    
    B[i] = A[i];
    
    if(A[i] == 1)Ans++;
    
  }

}

for(ll i = N/2; i > 0; i--){

  ll j = 2, cnt = 0;

  while(i*j <= N){

    cnt += B[i*j];j++;

  }

  if(cnt%2 != A[i]){B[i] = 1;Ans++;}

}
  
cout << Ans << endl;  
  
rep(i, 1, N + 1){
  
  if(B[i])cout << i << " ";
  
}
  
}