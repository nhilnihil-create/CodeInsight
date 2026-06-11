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
	int n, max = -1, max2 = -1, maxindex = -1;
	cin >> n;
	rep(i, n)
	{
		int x;
		cin >> x;
		if (x >= max)								// もし、maxが更新されたら
		{
			max2 = max;								// maxだった値を2番目に大きい数として記録
			max = x;								// maxを更新
			maxindex = i;						    // 何番目の値が最大値か記録
		}
		else if (x > max2) max2 = x;				// max未満でmax2より大きかった場合
	}
	if (max2 == -1) max2 = max;						// 2番目に大きい値がなかった場合
	rep(i, n)
	{
		if (i != maxindex) cout << max  << endl;
		else               cout << max2 << endl;	// 最大値が除かれた場合2番目に大きい値
	}
	return 0;
}