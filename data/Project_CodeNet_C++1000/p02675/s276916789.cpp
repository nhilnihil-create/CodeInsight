#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	string ans = "hon";
	switch (N % 10) {
		case 3:
			ans = "bon";
			break;
		case 0:
		case 1:
		case 6:
		case 8:
			ans = "pon";
			break;
		defalut:
			ans = "hon";
			break;
	}
	cout << ans << "\n";

	return 0;
}
