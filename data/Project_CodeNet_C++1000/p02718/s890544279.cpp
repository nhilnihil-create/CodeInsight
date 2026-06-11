// ABC161B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int all = 0;
	int a[1010] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all += a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]*4*m >= all) cnt++; // 移項して除算を使わない
	}
	if (cnt >= m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
