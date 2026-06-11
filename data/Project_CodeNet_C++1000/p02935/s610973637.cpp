#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v.at(i);

	sort(v.begin(), v.end());

	double ans = v.at(0);
	for(int i = 1; i < n; i++){
		ans = (v.at(i)+ans)/2;
	}

	cout << ans << endl;
	return 0;
}