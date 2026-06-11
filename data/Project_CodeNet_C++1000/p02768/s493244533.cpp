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
ll N, a, b, Ans = 0;cin >> N >> a >> b;
ll prime = 1000000007;

Ans += (F(2, N, prime) - 1)%prime;

ll Xa = N%prime, Ya = 1, Xb = N%prime, Yb = 1;

rep(i, 1, a){

    Xa *= (N - i);Xa %= prime;

}

rep(i, 1, b){

    Xb *= (N - i);Xb %= prime;

}
  
rep(i, 0, a){

    Ya *= (a - i);Ya %= prime;

} 
  
rep(i, 0, b){

    Yb *= (b - i);Yb %= prime;

} 

Ans -= ( F(Ya, prime - 2, prime)*Xa )%prime; 
Ans -= ( F(Yb, prime - 2, prime)*Xb )%prime;

cout << (Ans + 2*prime)%prime;
}