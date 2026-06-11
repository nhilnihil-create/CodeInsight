#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	ll h, w;
	cin >> h >> w;
	if (min(h, w) == 1) {
		cout << 1 << endl;
		return 0;
	}
	cout << ((h + 1) / 2) * ((w + 1) / 2) + (h / 2) * (w / 2) << endl;
}
