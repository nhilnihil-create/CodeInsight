#include<bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define RREP(i, n) for(int (i) = 0; (i) <= (n); (i)++)
#define REPR(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for(int (i) = (m); (i) < (n); (i)++)
#define FORD(i, m, n) for(int (i) = (m); (i) >= (n); (i)--)

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int a[200000]={0};
	REP(i, n) {
		cin>>a[i];
	}
	sort (a , a + n);
	REP(i, n) {
		if(a[i]==a[i+1]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}