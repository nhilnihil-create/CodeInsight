#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
  	while (true) {
       	c-=b;
      	if (c<=0) {cout << "Yes\n"; return 0;}
      	a-=d;
      	if (a<=0) {cout << "No\n"; return 0;}
    }
}