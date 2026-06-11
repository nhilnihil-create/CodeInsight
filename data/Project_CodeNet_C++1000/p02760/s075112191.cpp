#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int a[10];
	rep(i,9){
		cin >> a[i];
	}
	int n;
	cin >> n;

	vector<int>b(n);
	vector<int>c(10);

	rep(i, n) {
		cin >>b[i] ;
	}

	int ans = 0;

	rep(i, n) {
		rep(j, 9) {
			if (b[i]==a[j]) {
				c[j] = 1;
			}
		}
	}
	
	if (c[4]==1) {
		if (c[0]==1&&c[8]==1) {
			ans++;
		}
		if (c[6] == 1 && c[2] == 1) {
			ans++;
		}
		if (c[1] == 1 && c[7] == 1) {
			ans++;
		}
		if (c[3] == 1 && c[5] == 1) {
			ans++;
		}
	}
	
	if (c[0] == 1 && c[1] == 1 &&c[2]==1) {
		ans++;
	}
	if (c[6] == 1 && c[7] == 1 && c[8] == 1) {
		ans++;
	}
	if (c[0] == 1 && c[3] == 1 && c[6] == 1) {
		ans++;
	}
	if (c[2] == 1 && c[5] == 1 && c[8] == 1) {
		ans++;
	}


	if (ans!=0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
