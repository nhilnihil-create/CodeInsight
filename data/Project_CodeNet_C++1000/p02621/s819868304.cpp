#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>

#define REP(i,a,b) for(int i = (a); i < b; ++i)
#define inf 1e9+10
#define MOD 1000000007

using ll = long long;
using namespace std;

int main() {
	int a;
	cin >> a;

	cout << a + pow(a, 2) + pow(a, 3);

	return 0;
}