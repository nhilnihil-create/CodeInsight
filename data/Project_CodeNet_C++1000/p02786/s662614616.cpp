#include <bits/stdc++.h>

using namespace std;

long long f(long long x) {return (x == 1 ? 1 : 2 * f(x/2) + 1);}
long long x;
int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	
  	cin >> x;
  	cout << f(x) << '\n';
  
	return 0; 
}