#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll A[N];
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  vector<ll> b(200010);
  vector<ll> c(200010);
  vector<bool> seen;
  for(ll j=0;j<N;j++){
    if(j+A[j]<N) b[j+A[j]]++;
    if(j-A[j]>=0) c[j-A[j]]++;
  }
  ll ans=0;
  seen.assign(200010, true); 
  for(ll j=0;j<N;j++){
    if(j+A[j]<N) {
      if(seen[j+A[j]]){
	//cout << j+A[j] << " " << b[j+A[j]] << " " << c[j+A[j]] << endl;
	ans+=b[j+A[j]]*c[j+A[j]];
	seen[j+A[j]] = false;
      }
    }
  }
  cout << ans << endl;
}
