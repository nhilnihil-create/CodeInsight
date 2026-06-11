#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n,i = 0,j=0;
	long long int ans=0;
	cin >> n;
	vector<long long>a(n);
	rep(i, n) {
		cin >> a.at(i);
		
		if (a.at(i) == 0) {
			cout << 0<< endl;
			return 0;
		}
		
		
	}
	rep(i,n){
		if (a.at(i) > 1000000000) {
			ans++;
		}
	}
	if (ans == 2) {
		cout << -1 << endl;
		return 0;
	}
	ans = 1;
	rep(i, n) {
		ans *= a.at(i);
		if (ans > 1000000000000000000||ans==0) {
			cout << -1 << endl;
			return 0;
		}
	
	}
	cout << ans << endl;
	return 0;
}
