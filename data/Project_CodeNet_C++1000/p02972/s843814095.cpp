#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int main() {
	int n;
	int sum = 0;
	int ans = 0;
	cin >> n;
	vector<int> a(n + 1),b(n+1),c(n+1);
	for (int i = 1; i < n + 1; i++) {
		cin >> a.at(i);
	}
	for (int i = n; i > 0; i--) {
		
		for (int j = 1; j * i < n + 1; j++) {
			sum += b.at(j * i);
		}
		if (sum % 2 == a.at(i)) b.at(i)=0;
		else {
			b.at(i)=1;
			ans++;
			c.at(ans-1) = i;
		}
		sum = 0;
	}
	
	cout << ans << endl;
	for (int i = 0; i < ans-1; i++) {
		cout << c.at(i) << " ";
	//	f = 1;
	}
	if (ans>=1)cout << c.at(ans - 1) << endl;
	return 0;

	
}