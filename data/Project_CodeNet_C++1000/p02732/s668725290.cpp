#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N];
	int c[N];
	rep(i,N) c[i] = 0;
	rep(i,N) {
		int a;
		cin >> a;
		a--;
		A[i] = a;
		c[a]++;
	}
	ll tot = 0;
	rep(i,N) {
		tot += (ll)c[i]*(c[i]-1)/2;
	}
	rep(i,N) {
		int a = A[i];
		cout << tot - (c[a]-1) << endl; 
	}
	return 0;
}
