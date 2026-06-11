#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for(int i =1;i < n ;i++) {
		int add = (n+i-1)/i -1;
		cnt+=add;
	}
	cout << cnt;
	return 0;
}