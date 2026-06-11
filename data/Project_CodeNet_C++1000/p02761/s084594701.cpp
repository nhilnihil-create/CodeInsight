#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	
	int n,m;
	cin >> n>>m;

	vector<int>a(n,-1);

	rep(i,m) {
		int s, c;
		cin >> s >> c;
		if (a[s-1]!=-1 && a[s - 1]!=c) {
			cout << -1<<endl;
			return 0;
		}
		else {
			a[s - 1] = c;
		}
	}

	if (a[0]==0 && n!=1) {
		cout << -1 << endl;
		return 0;
	}
	else if(a[0] == -1 && n != 1) {
		a[0] = 1;
	}

	rep(i,n){
		if (a[i]!=-1) {
			cout << a[i];
		}
		else {
			cout << 0;
		}
	}

	return 0;
}
