#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if(n % 2 || n == 0)
		return cout << 0, 0;
	long long answer = 0;
	answer += n / 10;
	n /= 10;
	while(n >= 5) {
		answer +=  n / 5;
		n /= 5;
	}
	cout << answer;
}		
