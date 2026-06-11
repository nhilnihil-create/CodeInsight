#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  if((B-A)%2==0){
    cout << (B-A)/2 << endl;
  }else{
    cout << min(N-B,A-1)+(B-A+1)/2 << endl;
  }
  
}