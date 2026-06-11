#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

bool JudgePrime(int n){
  for (int i=2; i<n; i++){
    if (n%i==0) return false;
  }
  return true;
}

int main(){
  int x; cin>>x;
  int ans = x;
  while(true){
    if (JudgePrime(ans)){
      cout << ans;
      return 0;
    }
    ans++;
  }
}