#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v1, v2;
	for(int i=0; i<n; i++){
	    int x, y;
	    cin >> x >> y;
	    v1.push_back(x + y);
	    v2.push_back(x - y);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << max(v1[n-1] - v1[0], v2[n-1] - v2[0]);
	return 0;
}