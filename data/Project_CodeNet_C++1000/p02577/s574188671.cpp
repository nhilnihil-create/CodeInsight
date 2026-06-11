#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	string n;
  	cin >> n;
  	int sum=0;
	rep(i, n.size()) sum += (int)n.at(i)-48;
  	if(sum%9==0) cout << "Yes" << endl;
  	else cout << "No" << endl;
  	return 0;  
}
