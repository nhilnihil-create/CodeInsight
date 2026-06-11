#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	int n;
  	cin >> n;
  
  	if(n == 1) cout << 1 << endl;
  	else if(n%2==0) cout << 0.5000000000 << endl;
  	else cout << (double)((n/2)+1)/n << endl;
  	return 0;  
}
