#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#define SIZE 1002
#define REP(i, n) for (int i = 0; i < (n); i++)
#define X first
#define Y second

using namespace std;

typedef pair<double, double> V;
typedef long long ll;

// グローバル変数
int n;

// 自作のソート関数
bool less_theta(V& i, V& j) {
	double theta_i = 0, theta_j = 0;
	if (i.X != 0 || i.Y != 0)
		theta_i = atan2(i.X, i.Y);
	if (j.X != 0 || j.Y != 0)
		theta_j = atan2(j.X, j.Y);

	return theta_i < theta_j;
}

double dis(V& v)
{
	return v.X * v.X + v.Y * v.Y;
}

int main(void) {

// 入力

	cin >> n;
	vector<V> v(n);
	REP(i, n)
	{
		cin >> v[i].X >> v[i].Y;
	}

// 処理

	sort(v.begin(), v.end(), less_theta);
	double ans = 0;
	REP(i, n)
	{
		// 初期化
		V v_(0, 0);
		REP(j, n)
		{
			v_.X += v[(i + j) % n].X;
			v_.Y += v[(i + j) % n].Y;
			ans = max(ans, dis(v_));
		}
	}
	

// 出力

	cout << setprecision(12) << fixed << sqrt(ans);
	return 0;
}