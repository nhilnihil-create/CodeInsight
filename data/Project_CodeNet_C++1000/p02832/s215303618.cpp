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
  int N; cin >> N;
  vi a(N);
  rep(i,N) cin >> a[i];
  int count = 0;
  int cur = 1;
  
  rep(i,N){
    if(a[i]==1) break;
    if (i == N-1) { cout << -1 << endl; return 0;}
  }
  
  rep2(i,0,N){
    if(a[i] == cur){cur++; continue;}
    else count++;
  }
  
  cout << count <<endl;
  return 0;
}