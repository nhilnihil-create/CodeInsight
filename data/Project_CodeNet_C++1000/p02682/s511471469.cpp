#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	ll A, B, C, K;
	cin >> A >> B >> C >> K;

	if (K <= A) cout << K << endl;
	else if (A < K && K < (A+B)) cout << A << endl;
	else cout << A - (K - A - B) << endl;
return 0;
}
