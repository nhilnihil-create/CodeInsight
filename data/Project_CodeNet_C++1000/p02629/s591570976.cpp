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
#define rep2(i,n) for(int i = (n - 1); i >= 0; i--)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

int main() {

	ll n;
	cin >> n;
	vector<ll> name;

	while (n > 0) {
	
		name.push_back(n%26);
		n--;
		n /= 26;
	}
	
	ll s = name.size();

	for (ll i = s - 1; i >= 0; i--) {
		if (name[i] == 0) {
			cout << 'z';
		}
		else {
			char a = 96 + name[i];
			cout << a;
		}
	}

	cout << endl;

	return 0;
}