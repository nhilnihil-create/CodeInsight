
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define INF 1000000000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool winner = true;
	while(a > 0 && c > 0){
		c -= b;
		if(c <= 0 ) break;
		a -= d;
		if(a <= 0){
			winner = false;
			break;
		}
	}
	if(winner) cout << "Yes" << endl;
	else cout << "No" << endl;	

	return 0;
}
