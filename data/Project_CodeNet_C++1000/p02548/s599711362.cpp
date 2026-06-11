#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007

int main() {
	int n;
	cin >> n;
	ll cnt=0;

	for(int a=1; a<n; a++) cnt += ((n-1)/a);
	cout << cnt << endl;


	return 0;
}
