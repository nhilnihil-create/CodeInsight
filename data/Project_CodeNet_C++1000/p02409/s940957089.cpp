#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define rep(i,a,n) for(int (i)=a;(i)<(int)(n);(i)++)
#define rrep(i,a,n) for(int (i)=(n)-1;(i)>=a;(i)--)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

const int INF = 1e9;

int main() {
  	int cnt[10][3][4];
	memset(cnt, 0, sizeof cnt);

	int n;
	cin >> n;

	rep(i,0,n) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;
		cnt[r-1][f-1][b-1] += v;
	}

	rep(i,0,4) {
		if (i>0) cout << "####################" << endl;
		rep(j,0,3) {
			rep(k,0,10) {
				cout << " " << cnt[k][j][i];
			}
			cout << endl;
		}
	}
}