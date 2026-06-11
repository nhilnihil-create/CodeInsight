#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll N, Ans = 0;
int main(){
cin >> N;
vector<ll> V(N + 1);
map<ll, ll> M;

rep(i, 1, N + 1){

  cin >> V[i];

  M[V[i]]++;

}

for(auto x : M )Ans += x.second*(x.second - 1)/2;

rep(i, 1, N + 1)cout << Ans - M[V[i]]*(M[V[i]] - 1)/2 + (M[V[i]] - 1)*(M[V[i]] - 2)/2 << endl;

}