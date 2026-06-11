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
  int A, B; cin >> A >> B;
  
  rep(i, 10100){
    int a, b;
    a = i*0.08; b = i*0.1;
    if(a == A && b == B){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}