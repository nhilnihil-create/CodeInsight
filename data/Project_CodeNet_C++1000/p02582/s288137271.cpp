#include <iostream>
#include <string>

using namespace std;
 
int main() {
	string s;
  	cin >> s;
  	int cnt{0}, res{0};
  	for (char c : s) {
    	if (c == 'S') {
        	cnt = 0;
        } else {
        	cnt++;
        }
      	res = max(res, cnt);
    }
  
  	cout << res << endl;
}