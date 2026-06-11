#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int a[2010];

int main() {
	int n;
	int m;

	cin >> n ;

	m=1e9+7;
	a[0]=1;
	a[1]=0;
	a[2]=0;
  	rep(i, n){
		a[i+3]=a[i+2]+a[i];
		a[i+3]%=m;
	}

	cout << a[n] << endl;
	return 0;
}