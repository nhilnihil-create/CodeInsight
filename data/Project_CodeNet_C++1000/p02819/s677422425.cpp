#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  const int lim = 1e6+100;
  int N; cin >> N;
  vector<bool> prime(lim,false);
  
  for(int i = 2; i*i < lim; ++i){
    if(prime[i] == true) continue;
    for(int j = i*i; j < lim; j += i) prime[j] = true;
  }
  
  for(int i = N; i < lim; ++i){
    if(prime[i] == false){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}