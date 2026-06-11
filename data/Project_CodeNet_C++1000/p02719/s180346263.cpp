#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long n, k; cin >> n >> k;
	if (n == k) cout << "0" << endl;
	else if (n < k) cout << min(n, k - n) << endl;
	else cout << min(n % k, k - (n % k)) << endl;
}