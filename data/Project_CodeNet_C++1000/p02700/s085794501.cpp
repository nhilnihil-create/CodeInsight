#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int main(){
	ll T = 1;
	//cin >> T;
	while (T--){
		int a;
		int b;
		int c;
		int d;
		cin >> a >> b >> c >> d;
		while (a > 0 && b > 0) {
          c = c - b;
          if (c <= 0) {
			  cout << "Yes" << endl;
			  return 0;
		  }
		  a = a - d;
		  if (a <= 0) {
			  cout << "No" << endl;
			  return 0;
		  }
	  }
	}
}