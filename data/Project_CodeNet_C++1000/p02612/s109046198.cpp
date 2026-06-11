#include <iostream>
using namespace std;
int main() 
{
	int n; cin >> n;
	if (n % 1000 == 0) cout << 0;
	else {
		int tmp = n;
		int cnt = 1;
		while (tmp > 1000){
			cnt++;
			tmp -= 1000;
		} 
		cout << cnt * 1000 - n;
	}
}