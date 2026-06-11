// T2020C2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n + 2);
	vector<int>b(n + 2);
	vector<int>c_sum(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a.at(i);
	}
	for(int j=0;j<k;j++) {
		for (int i = 1; i <= n; i++)
		{
			int lp = i - a.at(i);
			if (lp < 0)
			{
				lp = 0;
			}
			b.at(lp) += 1;
			int rp = i + a.at(i) + 1;
			if (rp > n + 1)
			{
				rp = n + 1;
			}
			b.at(rp) -= 1;
		}
		c_sum.at(0) = b.at(0);
		for (int i = 1; i <= n; i++)
		{
			c_sum.at(i) = c_sum.at(i - 1) + b.at(i);
		}
		if (a == c_sum) { // vectorの比較
			break; // 変化がなくなったら、終わり
		}
		else {
			a = c_sum; // vectorのコピー
			fill(b.begin(), b.end(), 0); // vector<int>bを０に戻す
		}
	}
	for (int i = 1; i <=n; i++)
	{
		cout << c_sum.at(i) << " ";
	}
	cout << endl;
	return 0;
}
