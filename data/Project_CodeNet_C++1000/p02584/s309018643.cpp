#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){

  long long X,K,D,ans;

  cin >> X >> K >> D;

  X = fabs(X);

  long long t = min(X/D,K);

  X = X - D*t;
  K = K - t;

  if(K == 0 || K%2 == 0){
    ans = X;
    cout << ans << endl;
    return 0;
  }

  else{
    ans = fabs(D-X);
    cout << ans << endl;
    return 0;
  }

}
