#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s;
	int cnt = 1, k=-1,pos=0,slen=0;
	cin >> s;
	char cc = s[0];
	slen = s.size();
	vector<pair<char, int>>p;
	vector<int>road,child(slen);
	for (int i = 1; i < slen; i++) {
		if (s[i] != cc) {
			k *= -1;
			if (k == 1)rep(j, cnt) { road.push_back(cnt - j); }
			else if (k == -1)rep(j, cnt) { road.push_back((j+1)*k); }
			cc = s[i];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	rep(i, cnt)road.push_back((i + 1) * -1);
	rep(i, slen) {
		pos = i + road[i];
		if (abs(road[i])%2 == 1) {
			if (0 < road[i]) pos--;
			else pos++;
		}
		child[pos]++;
	}
	rep(i, slen - 1)cout << child[i] << " ";
	cout << child[slen - 1] << endl;
	return 0;
}

