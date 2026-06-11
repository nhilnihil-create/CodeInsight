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
#include <utility>  
#include <set>
#include<unordered_set>
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

 
int f[100001];
 

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


int arr[200001];

int digit(int n) {

	int cnt = 0;
	
	while (n) {

		n /= 10;
		cnt++;

	}

	return cnt;
}

int binarySearchLessThanOrEqual(int des) {

	int l = 0;
	int r = 1000000000;

	while (l <= r) {

		int mid = (l + r) / 2;

		if (mid > des) {

			r = mid - 1;

		}
		else {
			l = mid + 1;
		}
	}

	return r;

}


double dis(double x, double y, double x2, double y2) {

	return sqrt( (x - x2)*(x - x2) +  (y - y2) * (y - y2) );

}


int x[10];
int y[10];

int a[10];
int32_t main() {

	IOS;

	for (int i = 0; i < 10; i++) {

		a[i] = i + 1;

	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {

		cin >> x[i] >> y[i];

	}

	double sum = 0;

	int prevX = 0;
	int prevY = 0;

	bool flag = true;
	int cnt = 0;
	do {



		for (int i = 1; i < n; i++) {
			
			sum += dis(x[a[i-1]], y[a[i-1]], x[a[i]], y[a[i]]);

		}

		cnt++;
	} while (next_permutation(a, a + n));
 
	//cout << n << endl;
	double result = sum / cnt;

	
	 cout << fixed << setprecision(10) << result << endl;
 
	 
 


}