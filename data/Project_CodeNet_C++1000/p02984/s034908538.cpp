#include <iostream>
using namespace std;

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  int a[100010];
  int n, ans;
  
  cin >> n;
  ans = 0;
  for (int i=0; i<n; i++){
    cin >> a[i];
    ans += i%2==0? a[i]: -a[i];
  }
  cout << ans;
  for (int i=1; i<n; i++){
    ans = 2*a[i-1] - ans;
    cout << " " << ans;
  }
  cout << endl;
  
  return 0;
}