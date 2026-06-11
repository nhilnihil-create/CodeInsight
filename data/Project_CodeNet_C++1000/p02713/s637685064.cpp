#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define INF 1000000000000
typedef long long ll;

int gcd(int a,int b) {
	if (a < b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	int rem = 0;
	while (true) {
		rem = a % b;
		if (rem == 0) {
			return b;
		}
		a = b;
		b = rem;
	}
}

int main() {
	int k, sum = 0, temp;
	cin >> k;
	REP(i, k) {
		REP(j,k) {
			REP(t,k) {
				temp = gcd(i+1, j+1);
				sum += gcd(temp, t+1);
			}
		}
	}
	cout << sum;
}