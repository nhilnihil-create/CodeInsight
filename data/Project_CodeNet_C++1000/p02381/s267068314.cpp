#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,n) for(long long int i=0;i<(n);i++)

#define PI 3.14159265358479

int main(){
	int n;
	vector<long double> s;
	while (cin >> n){
		if (n == 0)break;
		long double x, m = 0, sum = 0;
		REP(i, n){
			cin >> x;
			s.push_back(x);
			m += x;
		}

		m = m / (long double)n;

		REP(i, n){
			s[i] -= m;
			s[i] = powl(s[i], 2.0);
			sum += s[i];
		}

		sum = powl(sum / (long double)n, 0.5);
		cout << fixed << sum << "\n";
		s.clear();
	}
	return 0;
}