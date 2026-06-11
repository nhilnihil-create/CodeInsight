// kyopro.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define For(i,N) for(ll i=0;i<N;i++)
int main()
{
	ll P, Q, R;
	cin >> P >> Q >> R;
	ll a = 0;
	a = P;
	if (a < Q)a = Q;
	if (a < R)a = R;

	cout << P + Q + R - a;
}
