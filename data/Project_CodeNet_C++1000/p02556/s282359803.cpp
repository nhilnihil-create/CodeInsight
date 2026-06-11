#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, A = 0, B = -10000000000, a = 10000000000, b = 10000000000, Ans = 0;

int main(){
cin >> N;

rep(i, 0, N){

  ll x, y;cin >> x >> y;

  A = max(x + y, A);B = max(x - y, B);

  a = min(x + y, a);b = min(x - y, b);

}

Ans = max(A - a, B - b);

cout << Ans;

}