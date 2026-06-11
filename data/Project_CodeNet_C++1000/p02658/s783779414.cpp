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
  ll A[N+10];
  ll  ans = 1;
  
  for(ll i=0;i<N;i++){
    ll a;
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    if(A[i]==0){
      cout << 0 << endl;
      return 0;
    }
  }
  for(ll i=0;i<N;i++){ 
    if(A[i] <= 1000000000000000000/ans){
      ans *= A[i];
    }else{
      ans = -1;
      cout << ans << endl;
      return 0;
    }
  }

  cout << ans<< endl;
}
