#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N, X;
	cin >> N >> X;
	int current = 0;
	int ans = 1;
	rep(i, N){
		int L;
		cin >> L;
		current += L;
		if (current <= X) ans++;
		else break;
	}	
	cout << ans << endl;
	return 0;
}
