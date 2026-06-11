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
  ll N;
  cin >> N;
  ll ans=0;
  ll n=0;
  for (n = 2; n*n < N; n++){
    if(N%n!=0) continue;
    ll N0=N;
    while(N0%n==0) N0/=n;
    if(N0%n==1) ans++;
    N0=N;
    ll m=N/n;
    while(N0%m==0) N0/=m;
    if(N0%m==1) ans++;
  }
  if (N==n*n) ans++;
  ans++;
  //cout << ans << endl;

  N--;
  n=2;
  ll a0=1;
  ll n0;
  for (n = 2; n*n <= N; n++){
    if(N%n!=0) continue;
    n0=1;
    while(N%n==0){
      N/=n; n0++;
    }
    a0*=n0;
  }
  if(N!=1) a0*=2;
  a0--;
  ans+=a0;

  cout << ans << endl;

  return 0;
}
