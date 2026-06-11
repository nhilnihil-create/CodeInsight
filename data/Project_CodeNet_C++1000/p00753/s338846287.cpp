#include<iostream>
#define Pr 259999
using namespace std;

bool prime[260000];
void eratos() {
	for (int i = 0;i <=Pr;i++)prime[i] = true;

	prime[0] = prime[1] = false;
	for (int i = 2;i*i <= Pr;i++) {
		if (prime[i]) {
			for (int j = i*2;j <= Pr;j+=i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	int a;
	eratos();
	while (cin >> a, a) {
		int ans = 0;
		for (int i = a+1;i <= a * 2;i++) {
			if (prime[i])ans++;
		}
		cout << ans << endl;
	}
}