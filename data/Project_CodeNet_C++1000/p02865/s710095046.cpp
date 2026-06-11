#include<iostream>
using namespace std;

int main() {
	int N,ans;
	cin >> N;
	if (N%2==0) {
		ans = N/2-1;
	}
	else {
		ans = (N-1)/2;
	}
	cout << ans;
}