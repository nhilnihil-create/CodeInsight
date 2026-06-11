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
	int n, one, ten, hundred;
	cin >> n;
	ten = n % 100;
	one = ten % 10;
	if ((n - ten) / 100 == 7 || (ten - one) / 10 == 7 || one == 7) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}