#include <iostream>
using namespace std;
int main(){
	int n, m, a,ans=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		ans += a;
	}
	if (ans > n)
		cout << "-1";
	else
		cout << n - ans;
}
