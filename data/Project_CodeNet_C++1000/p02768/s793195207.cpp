#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
   
int sum(int l, int r) {

	return (l + r)*(r - l + 1) / 2;

}

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}

}

int arr[100001];
int f[100001];
int ma[100001];
int ans[100001];

int Find(int x) {

	if (x == f[x])
		return x;

	return f[x] = Find(f[x]); 

}
const int Mod = 1e9 + 7;

long long fastPower(long long base, long long power) {
	long long result = 1;
	while (power > 0) {
		if (power & 1) { 
			result = result * base % Mod;
		}
		power >>= 1; 
		base = (base * base) % Mod;
	}
	return result;
}
 
int Inv(int x) {
	return fastPower(x, Mod - 2);
}


int nChoosek(int n, int k) {
 
	int ans = 1;

	for (int i = 1; i <= k; ++i) 
		ans = ans * Inv(i) % Mod *(n - i + 1) % Mod;

	return ans % Mod;


}




int32_t  main() {

	IOS;

	int n, a, b;

	cin >> n >> a >> b;

	int ans = fastPower(2, n) - 1;

	ans -= nChoosek(n, a);
	ans -= nChoosek(n, b);

	ans = (ans%Mod + Mod) % Mod;

	cout << ans << endl;
 
}
