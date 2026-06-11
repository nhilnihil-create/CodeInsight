#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, t;
int main() {
	cin >> x >> n;
  	for (int i=0; i<n; i++) {
      cin >> t; x-=t;
    }
  	cout << (x<0 ? -1 : x); 
}