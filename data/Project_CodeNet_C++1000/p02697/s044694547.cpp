#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int num;
	if (m % 2 != 0) {		// どこで半分にするか？
		if (n % 2 != 0) {
			num = n / 2;
		} else {
			num = n / 2 - 1;
		}
	} else {
		if (n % 2 != 0) {
			num = n / 2 - 1;
		} else {
			num = n / 2 - 1;
		}
	}

	int cnt = 0;
	int start = 0;
	int end = num;
	while (cnt < m) {
		cout << start + 1 << " " << end + 1 << endl;
		start++;
		end--;
		if (start >= end) {		// 前半グループが終わったら後半グループへ
			start = num + 1;
			if (n % 2 != 0) {
				end = n - 1;
			} else {
				end = n - 2;
			}
		}
		cnt++;
	}

}
