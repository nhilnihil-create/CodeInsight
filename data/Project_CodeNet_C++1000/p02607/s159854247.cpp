#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2;
int a[mxN];
int n;
int main()
{
	cin >> n;
	int cnt = 0;
	for(int i =0; i < n; i++){
		cin >> a[i];
		if((i+1)&1 && a[i]&1){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
