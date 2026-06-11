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
	ll N;
	cin >> N;
	vector<int>a(N+1);
	rep(N) {
		cin >> a[i+1];
	}
	vector<int>ans(N + 1,-1);

	map<int, int>cnt;
	for (int i = N; i >= 1; i--) {
		int c = 0;
		for (int j = 2; i * j <= N; j++) {
			c += ans[i * j];
		}
		c += a[i];
		ans[i] = c % 2;
		if (ans[i] == 1)
			cnt[i]++;
	}
	cout << cnt.size()<<endl;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		cout << it->first << " ";
	}
}
