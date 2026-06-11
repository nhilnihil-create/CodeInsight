#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void fcn(ll &a, ll &b){
	cout << a << " " << b << endl;
	a-=b;
	return;
}

int main(){
	int n;
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);

	ll m=0;
	if(a[0]>=0){
		m=-a[0];
		for(int i=1; i<n; i++) m+=a[i];
		cout << m << endl;

		for(int i=1; i<n-1; i++) fcn(a[0], a[i]);
		fcn(a[n-1], a[0]);
	}else if(a[n-1]<=0){
		m=a[n-1];
		for(int i=0; i<n-1; i++) m-=a[i];
		cout << m << endl;

		for(int i=n-2; i>=0; i--) fcn(a[n-1], a[i]);
	}else{
		int k=0;
		for(int i=0; i<n; i++){
			if(a[i]>=0) m+=a[i];
			else{
				m-=a[i];
				k++;
			}
		}
		cout << m << endl;

		for(int i=k; i<n-1; i++) fcn(a[0], a[i]);
		fcn(a[n-1], a[0]);
		for(int i=1; i<k; i++) fcn(a[n-1], a[i]);
	}
	return 0;
}