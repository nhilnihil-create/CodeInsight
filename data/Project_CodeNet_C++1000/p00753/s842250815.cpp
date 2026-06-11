#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

bool isprime[300000];
int data[150000];

int main(int argc, char **argv){
	int n;
	int cnt;
	int checkcnt = 0;
	for (int i = 0; i < 300000; i++) {
		isprime[i] = true;
	}
	while (cin >> n && n != 0) {
		int cnt = 0;
		for (int i = 2; i <= sqrt(2 * n); i++) {
			for (int j = 2; j <= (2 * n) / i; j++) {
				isprime[i * j] = false;
			}
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isprime[i]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}