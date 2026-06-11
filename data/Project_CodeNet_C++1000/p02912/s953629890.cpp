#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, M, Ans = 0;
priority_queue<ll> Q;

int main(){
cin >> N >> M;

rep(i, 0, N){

  ll a;cin >> a;

  Q.push(a);

}

rep(i, 0, M){

  ll m = Q.top();

  Q.pop();

  Q.push(m/2);

}

rep(i, 0, N){

  Ans += Q.top();

  Q.pop();

}
cout << Ans;
}