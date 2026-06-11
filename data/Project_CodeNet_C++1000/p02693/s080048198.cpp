#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int k, a, b;
	cin >> k >> a >> b;
	if (a <= b / k * k)cout << "OK" << endl;
	else cout << "NG" << endl;
	return 0;
}




