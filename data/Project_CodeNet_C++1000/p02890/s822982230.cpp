#include<iostream>
#include<vector>

using namespace std;

int num[300030];//num[x]=x枚以上重複しているカードの種類数
int cnt[300030];//cnt[x]=数xのカードの枚数

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		x--;//0-indexedにする(なんとなく)
		cnt[x]++;
	}
	for (int i = 0; i < N; i++) {
		num[cnt[i]]++;
	}
	for (int i = N; i >= 0; i--) {
		num[i] += num[i + 1];//後ろからの累積和
	}

	int sum = N;//使えるカードの枚数
	int c = N;//操作回数
	for (int k = 1; k <= N; k++) {
		//sumがk*c以上になるまでcを減らしていく
		while (sum<k*c) {
			sum -= num[c];//cを1減らすときに、使えるカードの枚数が(重複がc枚以上のカードの種類数)だけ減る
			c--;
		}
		cout << c << endl;
	}
}
