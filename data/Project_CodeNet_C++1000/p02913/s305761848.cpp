#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mxN = 1e5 + 5, mod = 1e9 + 7, base = 31, base2 = 37;
int power_B[mxN], power_B2[mxN], hashing[mxN], hashing2[mxN];
string s;

int mul(long long x, int y) {
	return x * y % mod;
}

int add(int x, int y) {
	x += y;
	if(x >= mod)
		x -= mod;
	return x;
}

int sub(int x, int y) {
	x -= y;
	if(x < 0)
		x += mod;
	return x;
}

int get_Answer(int l, int r) {
	if(!l)
		return hashing[r];
	
	return sub(hashing[r], mul(hashing[l - 1], power_B[r - l + 1]));
}

int get_Answer2(int l, int r) {
	if(!l)
		return hashing2[r];
	
	return sub(hashing2[r], mul(hashing2[l - 1], power_B2[r - l + 1]));
}

bool can(int x) {
	map<int, vector<pair<int, int>>> mp;
	int n = s.size();
	bool ok = false;
	int cnt = 0;
	for(int i = x - 1; i < n; ++i) {
		int current_Hash = get_Answer(cnt, i);
		mp[current_Hash].push_back({cnt, i});
		++cnt;
	}
	map<int, vector<pair<int, int>>> :: iterator it = mp.begin();
	while(it != mp.end() && !ok) {
		for(pair<int, int> &cur : (it-> second)) {
			for(pair<int, int> &cur2 : (it-> second)) {
				if(cur2.first > cur.second)
					ok = true;
			}
		}
		++it;
	}
	return ok;
}

int main() {
	int n;
	cin >> n;
	cin >> s;
	power_B[0] = power_B2[0] = 1;
	for(int i = 1; i < n; ++i) {
		power_B[i] = mul(power_B[i - 1], base);
		power_B2[i] = mul(power_B2[i - 1], base2);
	}
	
	int current_Hash = 0;
	for(int i = 0; i < n; ++i) {
		hashing[i] = add(s[i] - 'a' + 1, mul(base, current_Hash));
		current_Hash = hashing[i];
	}
	
	current_Hash = 0;
	for(int i = 0; i < n; ++i) {
		current_Hash = add(s[i] - 'a' + 1, mul(power_B2[i], current_Hash));
		hashing2[i] = current_Hash;
	}
	int low = 1, high = n, answer = 0, mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if(can(mid)) {
			answer = max(answer, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << answer;
}
