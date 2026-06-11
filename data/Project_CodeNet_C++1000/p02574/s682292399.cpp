#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

vector<bool> P;
map<ll, ll> M;

void prime_factor(ll N){

bool C = 1;

while(C){

C = 0;

    rep(i, 2, sqrt(N)){

    if(N%i == 0){M[i]++;N /= i;C = 1;break;}
   
    }

}

M[N]++;

}

ll gcd(ll N, ll M){

if(N%M == 0)return M;

else return gcd(M, N%M);

}

int main(){
ll N;cin >> N;
vector<ll> A(N);
vector<ll> Prime;
map<ll, bool> m;
  
bool C = 0, D = 1;

rep(i, 0, N)cin >> A[i];
  
ll G = A[0];
  
rep(i, 0, N){

  ll a = A[i];
  
  if(a != 1)prime_factor(a);

  for(auto x : M ){

    if(!m[x.first])m[x.first] = 1;

    else{C = 1;break;}

  }

  M.clear();

  if(C)break;

}

rep(i, 0, N - 1){

  G = gcd(G, A[i + 1]);

  if(G == 1){D = 0;break;}

}

//cout << G << endl;
  //for(auto x : M)cout << x.first << " " << x.second << endl;
  
if(!C)cout << "pairwise coprime";
else{

  if(D)cout << "not coprime";
  
  else cout << "setwise coprime";

}
}