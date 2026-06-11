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
  int N, D; cin >> N >> D;
  vvi x(N, vi(D));
  rep(i,N)rep(j,D) cin >> x[i][j];
  int count = 0;
  rep(i,N){
    rep2(j, i+1, N){
      float l = 0; 
      rep(k,D) l += pow(x[i][k]-x[j][k],2);
      l = sqrt(l);
      if(floor(l)==l) count++;
    }
  }
  cout << count << endl;  
  return 0;
}