#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<n; i++)


int main(){
	int n;
	cin >> n;

	vector<int>p(n);
	rep(i, n) {
		cin >> p[i];
	}

	int ans = 0;
	repr(i, 1, n-1) {
		if ((p[i - 1] < p[i]) && (p[i] < p[i + 1])) {
			ans++;
		}
		else if ((p[i - 1] > p[i]) && (p[i] > p[i + 1])) {
			ans++;
		}
	}

	cout << ans << endl;
}