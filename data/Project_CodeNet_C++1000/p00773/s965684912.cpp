#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int cal(int val,int tax) {
	return val * (100 + tax) / 100;
}
int main(){
	int x, y, s;
	while (cin >> x >> y >> s) {
		if (x == 0)break;
		int ma = 0;
		for (int i = 1; i < s; i++) {
			for (int j = i; j < s; j++) {
				if (cal(i, x) + cal(j, x) == s) {
					ma = max(ma, cal(i, y) + cal(j, y));
				}
			}
		}
		cout << ma << endl;
	}
	return 0;
}
