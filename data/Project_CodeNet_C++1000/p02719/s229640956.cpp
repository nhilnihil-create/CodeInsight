#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = -1; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;


int main() {

	ll n, k;

	cin >> n >> k;

	ll n1 = n % k;
	ll n2 = -1*(n1-k);
	

	if (n1 <= n2) { cout << n1 << endl; }
	else {
		cout << n2 << endl;
	}

	return 0;
}