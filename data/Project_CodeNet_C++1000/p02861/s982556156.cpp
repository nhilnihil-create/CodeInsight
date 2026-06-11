#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
double kyori(P a, P b) {
	double kyori;
	kyori = sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
	return kyori;
}
int main(void) {
	int n;
	cin >> n;
	vector<P>p(n);
	vector<ll>b(n);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}

	for (int i = 1; i <= n; i++) {
		b[i-1] = i;
	}
	
	double sum = 0;
	do {
		for (int i = 0; i < n - 1; i++) {
			sum += kyori(p[b[i] - 1], p[b[i + 1] - 1]);
		}
		
	} while (next_permutation(b.begin(), b.end()));
	int index = 1;
	for (int i = n; i >= 1; i--) {
		index *= i;
	}
	cout << fixed<<setprecision(10)<<sum / index << endl;
	return 0;
}
