#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n;
  bool once = false, twice = false;
  while(n--) {
    cin >> x >> y;
    if(x==y) {
    	if(!once) {
        	once = true;
        }
      	else if(!twice) {
        	twice = true;
        }
      	else { 
        	cout << "Yes"; 
      		return 0;
      	}
    }
    else {
    	once = twice = false;
    }
  }
    cout << "No";
	return 0;
}