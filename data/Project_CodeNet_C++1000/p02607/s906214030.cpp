#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, ans = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i += 2)
		if (num[i] % 2) ans += 1;
	cout << ans << '\n';
	return 0;
}
