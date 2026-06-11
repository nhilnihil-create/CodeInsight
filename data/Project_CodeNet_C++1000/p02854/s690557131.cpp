#include <iostream>
using namespace std;

#define ABS(X) ((X)<0?-(X):(X))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
  int n;
  long long ans, acc[200010];
  
  cin >> n;
  acc[0] = 0;
  for (int i=0; i<n; i++){
    long long t; cin >> t;
    acc[i+1] = acc[i] + t;
  }
  ans = acc[n];
  for (int i=0; i<n; i++){
    long long l,r;
    l = acc[i];
    r = acc[n]-acc[i];
    ans = MIN(ans, ABS(r-l));
  }
  cout << ans << endl;
  return 0;
}
