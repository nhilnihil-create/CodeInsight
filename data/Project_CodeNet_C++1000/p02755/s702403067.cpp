#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int t8 = 0, t10 = 0;
	int x = 10;
	while (t8<=A && t10 <=B) {
		t8 = x*8/100; t10 = x/10;
		if (t8==A && t10==B) {
			cout << x << endl;
			return 0;
		}
		x++;
	}
	cout << -1 << endl;

	return 0;
}
