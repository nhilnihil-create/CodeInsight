#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  long long X, K, D;
  cin >> X >> K >> D;
  if(X<0) X = -X;
  long long ans;
  long long r = X % D;
  long long a = (X-r) / D;
  if(K-a<=0){
    ans = X - K*D;
  }else if((K-a)%2==0){
    ans = r;
  }else{
    ans = D - r;
  }
  cout << ans;
  return 0;
}
