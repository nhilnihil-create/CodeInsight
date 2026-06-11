#include <bits/stdc++.h>
using namespace std;
int main() {
  	long long N;
  	cin >> N;
	long long res = 0;
  			for(long long a = 1; a <N; a++){
      					res += (N-1)/a;
        	}
	cout << res << endl;
}
