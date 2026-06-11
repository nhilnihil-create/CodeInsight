#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int turn = -1;
	while(a > 0 && c > 0) {
		if(turn == -1) {
			c -= b;
		}
		if(turn == 1) {
			a -= d;
		}
		turn *= -1;
	}
	string s = "No";
	if(a > c) s = "Yes";
	cout << s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
