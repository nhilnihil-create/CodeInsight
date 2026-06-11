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
  for(int i=0;i<N;i++){
    cin >> A[i];
    A[i] = -A[i];
  }
  sort(A,A+N);
  ll ans=0;
  for(int i=2;i<N+1;i++){
    ll m = floor(i/2) + 1;
    //cout << m << endl;
    ans -= A[i-m];
  }
  cout << ans << endl;
}
