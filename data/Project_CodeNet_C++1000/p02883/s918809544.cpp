#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> F(N);

  for(int i=0;i<N;i++) cin >> A[i];
  for(int i=0;i<N;i++) cin >> F[i];

  sort(A.begin(),A.end());
  sort(F.begin(),F.end(),greater<ll>());

  ll l=-1,r=1000000000100;

  while(l+1!=r){
    ll v=(l+r)/2;
    ll k=0;
    for(int i=0;i<N;i++){
      k+=max((ll)0,A[i]-v/F[i]);
    }
    //cout << v << " " << k << endl;
    if(k<=K){
      r=v;
    }else{
      l=v;
    }
  }

  cout << r << endl;

  return 0;
}
