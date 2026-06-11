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

	for (ll i = 2; i*i <= nx;i++){
		e = 0;
		ecnt = 1;
		while (N%i == 0){
			N = N / i;
			e++;
			if (e==ecnt){
				e = 0;
				ecnt++;
				con++;
				//cout << "i="<<i << endl;
			}
		}
	}
	if (N != 1)	con++;

	cout << con << endl;
	return 0;
}