#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n-1);
	for(int &e : a)
		cin >> e;
	for(int &e : b)
		cin >> e;
	for(int &e : c)
		cin >> e;
	
	long long xD = 0;
	for(int i = 0;i < n-1;++i)
		if(a[i+1] - a[i] == 1)
			xD += (c[a[i]-1]);
	for(int i = 0;i < n;++i)
		xD += (b[a[i]-1]);

	cout << xD << '\n';
}
