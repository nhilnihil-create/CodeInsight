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
	ll N, nx, e, ecnt, a, con = 0;

	cin >> N;
	nx = N;

	if (N % 10 == 3){
		cout << "bon" << endl;
		return 0;
	}
	else if ((N % 10 == 0) || (N % 10 == 1) || (N % 10 == 6) || (N % 10 == 8)){
		cout << "pon" << endl;
		return 0;
	}

	cout << "hon" << endl;
	return 0;
}