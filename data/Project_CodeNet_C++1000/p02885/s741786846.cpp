#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	int a, b;
  	cin >> a >> b;
  
  	if(a-2*b <0) cout << 0 << endl;
  	else cout << a-2*b << endl;
  	return 0;  
}
