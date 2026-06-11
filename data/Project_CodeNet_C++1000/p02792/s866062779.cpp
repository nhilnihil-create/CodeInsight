#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, M;

ll f(ll A){
ll countA = 0;

while(A > 0){
A /=10;
countA++;}
return countA;
}

ll F(ll a, ll b){
  
if(b > f(a))return -1;

else{
  
  rep(i, 0, b - 1)a /= 10;

  return a%10;
  
}

}

int main() {
ll Ans = 0;cin >> N;
vector<vector<ll>> V(10, vector<ll> (10));

rep(i, 1, N + 1){

  V[F(i, f(i))][F(i, 1)]++;
  
  //cout << F(i, 1) << " " << F(i, f(i)) << endl;

}

rep(i, 0, 10){

  rep(j, 0, 10){

    Ans += V[i][j]*V[j][i];

  }
}

cout << Ans;

}