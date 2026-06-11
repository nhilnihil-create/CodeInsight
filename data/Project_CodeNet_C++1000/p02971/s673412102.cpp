#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
bool  Array_check(ll y, ll x,ll d,ll w) {
	if (x < 0 || x >= w || y<0 || y>=d) {
		return false;
	}
	else {
		return true;
	}
	
}

//小文字=大文字+32

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	int nm=0;
	int m=0;
	rep(i, n) {

		if (a[i] > m) {
			m = a[i];
		}
		else if(a[i] > nm){

			nm = a[i];
		}
	}
	rep(i, n) {
		if (m != a[i]) {
		
			cout << m<<endl;
		}
		else {
			cout << nm<<endl;
		}
	}

}
	

