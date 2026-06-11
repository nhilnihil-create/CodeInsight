#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll cnt[10][10];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int head, tail = i%10, num = i;
		while(num/10 > 0){
			num /= 10;
		}
		head = num;
		cnt[head][tail]++;
	}
	ll ans = 0;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			ans += cnt[i][j] * cnt[j][i];
		}
	}
	cout << ans << endl;
	return 0;
}