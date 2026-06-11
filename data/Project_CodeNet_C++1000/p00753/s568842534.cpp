#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int n;
	int i, j;
	int isprime[246913];
	fill(isprime, isprime + 246913, 1);
	isprime[0] = isprime[1] = 0;
	for (i = 2; i <= 246912; i++) {
		if (isprime[i] == 1) {
			for (j = i * 2; j <= 246912; j += i) {
				isprime[j] = 0;
			}
		}
	}
	int sum[246913] = {};
	sum[0] = 0;
	for (i = 1; i <= 246912; i++) {
		sum[i] = sum[i - 1] + isprime[i];
	}
	while (cin >> n) {
		if (n == 0)break;
		cout << sum[2 * n] - sum[n] << endl;
	}
	return 0;
}
