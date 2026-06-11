#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int a[5];

	rep(i, 5) {
		cin >> a[i];
	
	}
	rep(i, 5) {
		if (a[i] == 0)
			cout << i+1 << endl;
	}
	return 0;
}