#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;



int main(){
ll N, Ans = 0;cin >> N;
queue<ll> Q;

rep(i, 1, 10)Q.push(i);

rep(i, 0, N){

    ll q = Q.front(), a = 10*q + q%10;
    
    if(q%10 != 0)Q.push(a - 1);
    
    Q.push(a);
    
    if(q%10 != 9)Q.push(a + 1);
    
    if(i == N -1)cout << Q.front();
    
    else Q.pop();}
    
}