#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	ll A, B, K;
	cin >> A >> B >> K;

	if(A >= K){
      cout << A - K << " " << B << endl;
    }else if(A < K && K - A <= B){
      cout << 0 << " " << B-K+A << endl;
    }else if(A < K && K - A > B){
      cout << "0 0" << endl;
    }
}
