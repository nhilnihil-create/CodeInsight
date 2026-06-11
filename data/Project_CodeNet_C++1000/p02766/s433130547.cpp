#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
using ll = long long;

using namespace std;
int main()
{/*三日目*/
//少数も使いたい割り算はしない方がいい(三日目）
// 数値の大きさ
	long a; cin >> a;
	int k; cin >> k;
	bool ok = true;
	int sum = 1;
	int zyo=k;
	while (ok) {
		if (a >= zyo) {
			sum++;
		}
		else
			ok = false;
		zyo *= k;


	}cout << sum;

}