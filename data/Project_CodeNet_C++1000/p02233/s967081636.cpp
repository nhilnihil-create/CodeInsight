#include <iostream>
using namespace std;

int fib(int n){
	int ans[45] = {1,1},i;
	for(i=2;i<=n;i++){
		ans[i] = ans[i-1]+ans[i-2];
	}
	return ans[n];
}

int main() {
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
