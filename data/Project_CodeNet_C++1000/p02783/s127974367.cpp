#include <iostream>
using namespace std;
  
int main() {
	int h, a;
  
  	cin >> h >> a;
  
  	int ans = (int)(h/a);
  	
  	if (h % a == 0)
  		cout << ans;
  	else
  		cout << ++ans;
}
