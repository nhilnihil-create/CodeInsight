#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d.at(i);
	
	sort(d.begin(), d.end());

	int diff = d.at(n/2) - d.at(n/2-1);
	cout << diff << endl;

	return 0;
}
