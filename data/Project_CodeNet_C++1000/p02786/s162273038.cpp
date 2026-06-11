#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	ll H, ans = 1;	//入力が10^22までの制限なので、int じゃ足りないから型は long long

	// 入力を受け取る
	cin >> H;

	// Hが何回2で割ると1以下になるか計算する。
	// Hが1以下になるまで割った数分2引きに分裂し、攻撃回数が増える。
	ll count = 0;
	while (H > 1)
	{
		count++;
		ans += pow(2,count);	// 攻撃回数(2の割った数乗)

		H /= 2;
	}

	cout << ans << endl;
	return 0;
}