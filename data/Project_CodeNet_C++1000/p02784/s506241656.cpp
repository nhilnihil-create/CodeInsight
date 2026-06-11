#include<bits/stdc++.h>
using namespace std;

int main() {
	int h,n; cin >> h >> n;
  	vector<int> a(n);
  	for (int i=0; i<n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if (h <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}