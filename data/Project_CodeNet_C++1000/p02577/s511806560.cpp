#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
 
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)
 
int main() {
	string N;
	cin >> N;
 
	ll sum = 0;
	REP(i, N.length()) {
		char buf = N[i];
		sum = (sum + atoi(&buf)) % 9;
	}
	if (sum == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
 
	return 0;
}