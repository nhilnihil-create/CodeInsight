#include <iostream>
#include<vector>
int n,q,k,a;
using namespace std;
int main(){
	vector<int> point(100006,0);cin >> n >> k >> q;
	for (int j = 0; j < q; j++) {
		cin >> a;++point[a - 1];
	}
	for (int i = 0; i < n; i++) {
		if (point[i] - q+k> 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}