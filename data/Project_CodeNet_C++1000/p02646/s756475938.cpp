#include <iostream>
typedef long long int ll;
using namespace std;
int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  ll total_distance = abs(a-b);
  ll interval_distance = (v-w)*t;
  if (total_distance <= interval_distance) {
  	cout << "YES";
  } else {
    cout << "NO";
  } 
  return 0;
}
  	
   
