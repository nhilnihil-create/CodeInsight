#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;
map<ll, ll> P;
map<ll, ll> Q;

rep(i, 1, N + 1){

    ll a;cin >> a;

    P[i + a]++;

    Q[i - a]++;

    }

for(auto p : P ){

    Ans += p.second*Q[p.first];

}

cout << Ans;

}
