#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define INF 1000000001
#define MOD 1000000007


using namespace std;
void  initialize(vector<int> &v, int n) {
	REP(i, n) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	return;

}


int main() {
	int n;
	double ave = 0, m=0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vector<int> v;
		initialize(v, n);
		REP(i, n) {
			ave += v[i];
		}
		ave /= n;
		REP(i, n) {
			m += (v[i] - ave)*(v[i] - ave);
		}
		m /= n;
		cout << fixed << setprecision(8) << sqrt(m) << endl;
		ave = 0;
		m = 0;
	}

	return 0;
}