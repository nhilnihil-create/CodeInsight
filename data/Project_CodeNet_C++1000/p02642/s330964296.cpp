#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, S = -1, Ans = 0;cin >> N;
vector<ll> V(N + 1);
map<ll, ll> P;

rep(i, 1, N + 1){
  
  cin >> V[i];
  
  P[V[i]]++;
  
}
  
ll M = *max_element(ALL(V));

vector<bool> A(M + 1, 1);

sort(ALL(V));
  
 ll a = 0, b = 0;

rep(i, 1, N + 1){
  
    if(a == 0){
      
      a = V[i];
      
      if(a == b){a = 0;continue;}
      
    }
  
    else{
    
      b = V[i];
      
      if(a == b){a = 0;continue;}
      
      a = 0;
      
    }

    rep(n, 1, floorl(M/V[i])){

        A[(n + 1)*V[i]] = 0;

    } 

}

rep(i, 1, N + 1){

    if(A[V[i]] && P[V[i]] < 2)Ans++;

}

cout << Ans;

}