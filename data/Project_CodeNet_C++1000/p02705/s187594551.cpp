#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<numeric>
#include<iomanip>
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ll long long
const double PI = 3.141592653589793;

using namespace std;

//最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

//階乗
ll fact(ll a) {
	int ans = 1;
	for (int i = 1; i <= a; i++) {
		ans *= i;
	}
	return ans;
}

//コンビネーション
ll combi(ll a, ll b) {
	return fact(a) / (fact(b) * fact(a - b));
}

int main() {
	double r;
	cin >> r;
	cout << PI * 2*r << endl;
	return 0;
}
