#include <iostream>
using namespace std;

const int mxN = 2e5 + 5;
int a[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int answer = 0, look = 1;
	if(n == 1)
		return cout << (a[1] == 1 ? 0 : -1), 0; 
	for(int i = 1; i <= n; ++i) {
		if(a[i] == look) {
			++look;
			continue;
		}
		++answer;
	}
	cout << (look == 1 ? -1 : answer);
}
