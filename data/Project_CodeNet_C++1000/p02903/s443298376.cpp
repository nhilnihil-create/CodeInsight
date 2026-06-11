#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (i <= b && j <= a) cout << 1;
			else if (i <= b) cout << 0;
			else if (j <= a) cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
}