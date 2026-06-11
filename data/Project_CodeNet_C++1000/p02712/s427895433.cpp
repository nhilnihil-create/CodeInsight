#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define INF 1000000000000
typedef long long ll;

int main() {
	int n;
	ll sum = 0;
	cin >> n;
	REP(i, n) {
		if ((i+1) % 3 != 0 && (i+1) % 5 != 0) {
			sum += i + 1;
		}
	}
	cout << sum;
}