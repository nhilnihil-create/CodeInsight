#include <iostream>

using namespace std;
int main() {
 	int l, r, d;
  	cin >> l >> r >> d;
  	int cnt = 0;
  
  	int prod = 0;
   //5 10 2
  
  	int num = 0;
 	while(prod <= r) {
      if(prod >=l && prod <=r)
	      ++cnt;
      ++num;
      prod = d*num;
      
    }
  
  cout << cnt << endl;
  
}