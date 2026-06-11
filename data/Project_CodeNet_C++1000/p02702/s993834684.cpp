#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
using namespace std;

const int mod = 2019;

int main() {
	string S;
	cin >> S;
	int digit = S.size();
	//小さな位から見るため、文字列を反転
	reverse(S.begin(), S.end());
	int x = 1; //位取り
	int sum = 0; //累積和
	long long ans = 0;
	vector<int> cnt(mod, 0); //累積和の登場回数
	for (int i = 0; i < digit; i++) {
		cnt[sum]++;
		sum += (S[i] - '0')*x;
		sum %= mod;
		ans += cnt[sum];
		x = x * 10 % mod; //位を更新
	}
	cout << ans << endl;
	return 0;
}