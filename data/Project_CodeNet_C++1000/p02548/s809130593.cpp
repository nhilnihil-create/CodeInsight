#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int c = 1; c < n; c++) {
  	int x = n - c;
    for (int i = 1; i * i <= x; i++) {
    	if (x % i == 0) {
        	if (x / i != i)
              ans++;
          	ans++;
        }
    }
  }
  
    cout << ans << endl;
	return 0;
}