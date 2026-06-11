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
	ll ans, n, a, b;							// 入力nの条件が10^18より long longにした
	cin >> n >> a >> b;							// 入力を受け取る

	ans = (n / (a + b)) * a;					// 割り切れた数 × 青ボールの数(a) は入っている
	if (n % (a + b) > a) ans += a;				//余りの中の青ボールを足す
	else				 ans += n % (a + b);

	cout << ans << endl;
	return 0;
}