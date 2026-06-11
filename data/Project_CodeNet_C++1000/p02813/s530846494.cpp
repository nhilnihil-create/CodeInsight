#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
      sum *= i;
    return sum;
}


int main(){
  ll n; cin >> n;
  ll k = facctorialMethod(n);
  vector<int> v(n);
  rep(i, n)
    v[i] = i+1;
  
  vector<int> P(n),Q(n);
  rep(i, n) cin >> P[i];
  rep(i, n) cin >> Q[i];
  int p, q; 
 
  rep(i, k){
    if(P == v) {p = i+1; break;} 
    next_permutation(v.begin(),v.end());
  }
  rep(i, n)
    v[i] = i+1;
  
  rep(i, k){
    if(Q == v) {q = i+1; break;}
    next_permutation(v.begin(),v.end());
  }
  
  cout << abs(p-q) << endl;
}