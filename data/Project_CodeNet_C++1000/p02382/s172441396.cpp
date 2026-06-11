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

void  inl(vector<int> &v, int n) {
	REP(i, n) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> x, y;
	double d=0;
	inl(x, n);
	inl(y, n);
	REP(i, 3) {
		REP(j, n) {
			d += pow(abs(x[j] - y[j]), i + 1);
		}
		cout << fixed << setprecision(8) << pow(d,1.00000000000000000/(i+1))<<endl;
		d = 0;
	}
	
	REP(i, n) {
		if (d < abs(x[i] - y[i])) d = abs(x[i] - y[i]);
	}
	cout << d << endl;


	return 0;
}