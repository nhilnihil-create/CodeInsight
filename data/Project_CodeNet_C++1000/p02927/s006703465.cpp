#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int m, d;
	cin >> m >> d;

	int cnt = 0;
	for(int mi=1;mi<=m;mi++) {
		for (int di = 1; di <= d; di++) {
			int d1 = di % 10;
			int d10 = di / 10;
			d10 %= 10;

			if (2 <= d1 && 2 <= d10 && d1*d10 == mi) cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}