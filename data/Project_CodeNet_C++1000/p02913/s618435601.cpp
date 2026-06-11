#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
string S;

class RollingHash {
	private:
		vector<long long> mod; // ハッシュなので、複数種類のmodで強化する
		const long long b = 1000000007LL; // 素数が望ましい
		int n;
		void init() {
			mod.push_back(1000000009LL);
			mod.push_back(1000003341LL);
		}

		// hs: 文字列のローリングハッシュ値
		// hs: hs[i+1] = hs[i] * b + s[i] (mod m)
		// s = "xyzw"
		// ""     hs[0] = 0 
		// "x"    hs[1] = x * b^0 
		// "xy"   hs[2] = x * b^1 + y * b^0
		// "xyz"  hs[3] = x * b^2 + y * b^1 + z * b^0
		// "xyzw" hs[4] = x * b^3 + y * b^2 + z * b^1 + w * b^0
		// "yz"   y * b^1 + z * b^0 = hs[3] - hs[1] * b^2
		vector<vector<long long> > hs;
		// pw: b^n (mod m)
		vector<vector<long long> > pw;

	public:
		// ローリングハッシュ構築
		// O(n)
		RollingHash(const string &s) : n(s.size()) {
			init();
			hs.resize(mod.size()), pw.resize(mod.size());
			for (int m = 0; m < mod.size(); m++) {
				hs[m].assign(n + 1, 0);//0で初期化
				pw[m].assign(n + 1, 0);//0で初期化
				hs[m][0] = 0;
				pw[m][0] = 1;
				for (int j = 0; j < n; j++) {
					pw[m][j + 1] = pw[m][j] * b % mod[m];
					hs[m][j + 1] = (hs[m][j] * b + s[j]) % mod[m];
				}
			}
		}

		// 部分文字列[l, r)のローリングハッシュ値計算
		// O(1)
		inline long long hash1(int l, int r) {
		return  ((hs[0][r] - hs[0][l] * pw[0][r - l]) % mod[0] + mod[0]) % mod[0];
		}

		inline long long hash2(int l, int r) {
		return  ((hs[1][r] - hs[1][l] * pw[1][r - l]) % mod[1] + mod[1]) % mod[1];
		}
};


int main(){
	cin >> N >> S;

	RollingHash rh(S);


	ll start = 0;
	ll end = S.size();

	while(start + 1 < end) {
		ll mid = (start + end)/2;

		//hash, minipos
		map<pair<ll, ll>, ll> memo;

		bool ok = false;
		rep(i, N - mid + 1) {
			ll hash1 = rh.hash1(i, i + mid);
			ll hash2 = rh.hash2(i, i + mid);
			if(memo.count(make_pair(hash1, hash2)) > 0 && memo[make_pair(hash1, hash2)] <= i - mid) {
				ok = true;
				break;
			}
			if(memo.count(make_pair(hash1, hash2)) == 0) {
				memo[make_pair(hash1, hash2)] = i;
			}
		}

		if(ok) {
			start = mid;
		} else {
			end = mid;
		}
	}
	cout << start << endl;

}

