#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main() {
  ll K; cin >> K;
  ll sum=0;
  
  rep(i,K+1){
    sum = sum*10 +7;
    sum%=K;
    if(sum == 0){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
