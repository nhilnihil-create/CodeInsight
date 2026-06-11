#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
  	cin >> n;
  	int r = 0;
  	for (int i = 1; i <= n; i++) {
     	int x;
      	cin >> x;
      	if ((x & 1) && (i & 1))
        	r++;
    }
  	cout << r;
}
