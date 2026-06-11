#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll X, Y, A, B, C, Ans = 0;
int main(){
cin >> X >> Y >> A >> B >> C;

priority_queue<ll> R;
priority_queue<ll> G;
priority_queue<ll> T;

rep(i, 0, A){
  
  ll x;cin >> x;

  R.push(x);

}

rep(i, 0, B){
  
  ll x;cin >> x;

  G.push(x);

}

rep(i, 0, C){
  
  ll x;cin >> x;

  T.push(x);

}

rep(i, 0, X){

  T.push(R.top());R.pop();

}

rep(i, 0, Y){

  T.push(G.top());G.pop();

}

rep(i, 0, X + Y){

  Ans += T.top();T.pop();
 
}

cout << Ans;

}