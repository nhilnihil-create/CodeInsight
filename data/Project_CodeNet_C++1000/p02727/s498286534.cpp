#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll M, m, A, B, C, X, Y, Ans = 0;cin >> X >> Y >> A >> B >> C;
m = X + Y;

deque<ll> P(A);
deque<ll> Q(B);
deque<ll> R(C);

rep(i, 0, A)cin >> P[i];
rep(i, 0, B)cin >> Q[i];
rep(i, 0, C)cin >> R[i];

sort(ALL(P));sort(ALL(Q));sort(ALL(R));

rep(i, 0, A - X)P[i] = 0;
rep(i, 0, B - Y)Q[i] = 0;

reverse(ALL(P));reverse(ALL(Q));reverse(ALL(R));
  
rep(i, 0, m){

    M = max(max(P[0], Q[0]), R[0]);
    
    Ans += M;

    if(M == P[0]){P.pop_front();continue;}

    if(M == Q[0]){Q.pop_front();continue;}

    if(M == R[0]){R.pop_front();continue;}
}
cout << Ans;
}