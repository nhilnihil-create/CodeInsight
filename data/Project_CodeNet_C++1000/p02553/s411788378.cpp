#include <iostream>
using namespace std;

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  long long a,b,c,d,ans;
  
  cin >> a >> b >> c >> d;
  ans = a*c;
  ans = MAX(ans, a*d);
  ans = MAX(ans, b*c);
  ans = MAX(ans, b*d);
  cout << ans << endl;
  
  return 0;
}