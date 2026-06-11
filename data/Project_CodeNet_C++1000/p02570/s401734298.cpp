#include <bits/stdc++.h>
using namespace std;

int main() {
 	long long x, y, z;
  	cin >> x >> y >> z;
  	long long ans = y * z;
  	if(ans < x) {
     	 cout << "No\n";
    }
  	else {
     	cout << "Yes\n";
    }
}
