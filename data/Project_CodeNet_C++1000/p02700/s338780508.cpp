#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d;
  	cin >> a >> b >> c >> d;
  	int i = 0;
  	while(a > 0 && c > 0) {
    	if(i)
          a -= d, i--;
      	else
          c -= b, i++;
    }
  	if(a > 0)
      cout << "Yes\n";
  	else
      cout << "No\n";
}
