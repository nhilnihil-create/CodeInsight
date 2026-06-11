#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i <= N; i++)
#define ll long long int
using namespace std;

ll Ans = 0;
map<ll, ll> A;map<ll, ll> B;
vector<ll> V;

void devisorA(ll m){
    
    rep(i, 1, sqrtl(m)){

        if(m%i == 0){

        A[i]++;A[m/i]++;

        }

    }

}

void devisorB(ll m){
    
    rep(i, 1, sqrtl(m)){

        if(m%i == 0){

        B[i]++;B[m/i]++;

        }

    }

}

void prime_judge(ll n){

bool C = 1;

    rep(i, 2, sqrtl(n)){

        if(n%i == 0){C = 0;break;}

    }

if(C)Ans++;

}

int main(){
ll a, b;cin >> a >> b;

devisorA(a);devisorB(b);

for(auto x : A ){

    if(min(x.second, B[x.first]) == 0)continue;

    V.push_back(x.first);

}
  
  //for(auto x : B )cout << x.first << " " << x.second;

rep(i, 0, V.size() - 1)prime_judge(V[i]);

cout << Ans;

}