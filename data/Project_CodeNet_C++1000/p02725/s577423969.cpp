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
int arr[200001];
int32_t  main() {

	IOS;

	int K, N;

	cin >> K >> N;
	 
	int maxi = 0;
	int mini = INT_MAX;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];	 
 
	}

	arr[N] = arr[0] + K;

	int l = 0;
	for (int i = 1; i <= N; i++) {

		
		l = max(l, arr[i] - arr[i - 1]);

	}

	

	cout << K-l << endl;


}
