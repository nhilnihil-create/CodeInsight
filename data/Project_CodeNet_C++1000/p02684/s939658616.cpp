#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  ll K;
  cin >> N >> K;
  ll A[N];
  ll b[N];
  ll c[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
    b[i] = -1;
  }
  ll now = 0;
  ll loop = 0;
  ll back = 0;
  ll start = 0;
  b[0] = 0;
  for(int i=1;i<N+1;i++){
    if(b[A[now]-1]!=-1){
      loop = i - b[A[now]-1];
      start = A[now]-1;
      back = b[A[now]-1]+1;
      break;
    }
    b[A[now]-1] = i;
    now = A[now]-1;
  }
  ll ans = 0;
  if(K>=back){
    ll p = (K-back)%loop;
    ans  = A[start];
    for(ll j=1;j<=p;j++){
      ans = A[ans-1];
    }
  }else{
    ans = A[0];
    for(ll j=1;j<K;j++){
      ans = A[ans-1];
    }   
  }
  cout << ans << endl;
}
