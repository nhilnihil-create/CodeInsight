#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>

int main() {
	int w, h,x,y;
	cin >> w >> h>>x>>y;
	double men = double(w) * double(h) / 2.0;
	cout <<fixed<< setprecision(12)<<men<<" ";
	int w2 = w / 2;
	int h2 = h / 2;
	if (2*x == w && h == 2*y) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;

}