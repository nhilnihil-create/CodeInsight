#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll F(ll N, ll a, ll p){
 
    if(a == 0)return 1;
 
    if(a%2 == 0 && a != 0)return (F(N, a/2, p)*F(N, a/2, p))%p;
 
    if(a%2 == 1)return N*F(N, a - 1, p)%p;
 
}

int main(){
ll x, y, k, K, n, N, Ans = 0;cin >> x >> y;
ll prime = 1000000007;
k = (x + y)/3;
n = min(2*k - x, 2*k - y);N = 1;
K = k - n + 1;
  
if((x + y)%3 != 0 || x > 2*k || y > 2*k){cout << 0;exit(0);}

if(n == 0){cout << 1;exit(0);}
  
else{
  
    rep(i, 1, n + 1){

        N *= i;N %= prime;

    }
  
}
  
rep(i, 1, n){

    K *= (k - n + 1) + i;K %= prime;

}

Ans = ( F(N, prime - 2, prime)%prime )*( K%prime );

cout << Ans%prime;
  
  return 0;
  
}