#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int ans = A + B + C;
	cout << ans - max(A, max(B, C)) << endl;
	return 0;
}