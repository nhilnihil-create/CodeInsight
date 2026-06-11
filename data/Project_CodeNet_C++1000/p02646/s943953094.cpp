#include <iostream>

#define REP(loop, n) for(int i = (loop) ; i < n ; ++i)

using namespace std;

int main(void)
{
	long A, B, V, W, T;
	cin >> A >> V;
	cin >> B >> W;
	cin >> T;

	// 距離
	long dst = abs(A - B);

	// 速度差
	long diff = V - W;

	if (V > W && dst <= T * diff)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	rewind(stdin);
	getchar();
	return 0;
}
