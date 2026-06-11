#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
nは偶数
自分以外のxorがわかっているので自分を求めなさい
xorは二回やると0になる
つまりn-1回やったときに残るのは最後の値だけ -> これで最後の値が特定できる
最後の値が特定できれば全体のxorがわかるのであとは、全体とxorしていくだけ
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int tmp = 0;
	for (int i = 0; i < n - 1; i++) tmp ^= a[i];
	int all = tmp ^ a[n - 1];
	for (int i = 0; i < n; i++) 
	{
		cout << (all ^ a[i]);
		if (i == n - 1) cout << endl;
		else cout << " ";
	}
	return (0);
}
