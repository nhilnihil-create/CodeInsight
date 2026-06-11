#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
const ll M = pow(10,9)+7;
const ll im = 1;

int main(){
  ll N;
  cin >> N;
  ll A[N];
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  ll bit[61] = {0};
  for(ll i=0;i<N;i++){
    for(int j=0;j<61;j++){
      if((im<<j)&A[i]) bit[j]++;
    }
  }
  ll ans = 0;
  for(int i=0;i<61;i++){
    ll sum = (bit[i]*(N-bit[i]))%M;
    ll val = (im<<i)%M;
    ans += (sum*val)%M;
  }
  cout << ans%M << endl;
}
