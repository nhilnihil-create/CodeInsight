#include <bits/stdc++.h>
using namespace std;

int main() {
	int j, tmp, ans = 0,min;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> n;
	pair<int, int> tmpair;
	cin >> j;
	for (int i = 1; i < (j + 1); i++) {
		cin >> tmp;
		n.push(make_pair(tmp, i));
	}
	for (int i = 0; i < j; i++) {
		tmpair = n.top();
		n.pop();

		if (i == 0) {
			min = tmpair.second;
			ans++;
		}
		else {
			if (min < tmpair.second) {
				continue;
			}
			else {
				min = tmpair.second;
				ans++;
			}
		}
	}
	cout << ans << endl;
	//<数値、順番>のpairにする
	//数値に基づいてpriority_queue(昇順)
	//queueから出した順番をpriority_queueに入れて自分より小さい値があればアウト

}