#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* f = new int[n + 1];
	for (int i = 1;i <= n;i++) {
		f[i] = 0;
	}
	for (int i = 1;i <= sqrt(n);i++) {
		for (int j = 1;j <= sqrt(n);j++) {
			for (int k = 1;k <= sqrt(n);k++) {
				int ans = i * i + j * j + k * k + i * j + i * k + j * k;
				if (ans <= n)f[ans]++;
			} 
		}
	}
	for (int i = 1;i <= n;i++) {
		cout << f[i] << endl;
	}
}