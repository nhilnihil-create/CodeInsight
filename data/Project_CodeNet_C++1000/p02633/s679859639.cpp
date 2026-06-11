#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	int X; cin >> X;

	int ans = 1;

	while(1) {
		if ((ans * X) % 360 == 0) {
			break;
		}
		ans++;	
	}
	cout << ans << endl;


	return 0;
}
