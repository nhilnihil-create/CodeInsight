#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	ll k, N;
	string s;

	cin >> k >> s;

	N = (ll)(s.length());

	if (k >= N){
		cout << s << endl;
	}
	else{
		cout << s.erase(k) << "..." << endl;
	}

	return 0;
}