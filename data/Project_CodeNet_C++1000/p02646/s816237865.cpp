#include <bits/stdc++.h>
using namespace std;

int main() {

  long long A, V, B, W, T;
  
  cin >> A >> V >> B >> W >> T;
  
  if (V > W) {
  	if ((V - W) * T >= abs(A -B)) {
    cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
  } else {
  	cout << "NO" << endl;
  }
  
    return 0;

}
