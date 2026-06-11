#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll N, M;

ll F(ll a, ll b){

rep(i, 1, N + 1 - b){
a /= 10;
}
return a %10;
}

int main() {

cin >> N >> M;

vector<ll> s(M);
vector<ll> c(M);

rep(i, 0, M)cin >> s[i] >> c[i];
bool C = 0;
if(N == 1)C = 1;

rep(n, pow(10, N - 1), pow(10, N)){
int count = 0;
if(C){C = 0;n--;}

    rep(i, 0, M){
    if(F(n, s[i]) == c[i])count++;
    }

if(count == M){cout << n;exit(0);}
}
cout << -1;
}