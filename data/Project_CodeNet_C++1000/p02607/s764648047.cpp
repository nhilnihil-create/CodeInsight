#include <iostream>
using namespace std;

int main() {

	int n; cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {

		int num; scanf("%d", &num);

		if(i % 2 == 1 && num % 2 == 1)
			ans ++;
	}	
	cout << ans << endl;
}