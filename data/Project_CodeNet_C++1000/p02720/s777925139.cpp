#include <bits/stdc++.h>
	
using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

template<class F, class S> ostream& operator<<(ostream& os, pair<F, S> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template<class T, class S> ostream& operator<<(ostream& os, map<T, S> &v) {
	os << "{";
	for(auto &i : v) cout << "{" << i.first << "," << i.second << "}";
	os << "}";
	return os;
}

template<class T> ostream& operator<<(ostream& os, set<T> &v) {
	os << "{";
	for(auto &i : v) cout << i << ",";
	os << "}";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> &v) {
	os << "[";
	if(v.size()) os << v[0];
	for(int i = 1; i < v.size(); ++i) os << "," << v[i];
	os << "]";
	return os;
}

/*----------------------------------------------------------------------------*/


long long tb[11][10][2];
vector<int> num;

long long dp(int i, int last, bool check) {
	if (i == -1) return 1;

	long long resp = 0;
	if (!check) {
		resp += (last + 1 <= 9) ? dp(i - 1, last + 1, check) : 0;
		resp += dp(i-1, last, check && (last == num[i]));
		resp += (last - 1 >= 0) ? dp(i - 1, last - 1, check) : 0;
	} else {
		resp += (last + 1 <= num[i]) ? dp(i - 1, last + 1, check && (num[i] == last + 1) ) : 0;
		resp += (last <= num[i]) ? dp(i-1, last, check && (last == num[i])) : 0;
		resp += (last - 1 >= 0 && last - 1 <= num[i]) ? dp(i - 1, last - 1, check && (num[i] == last - 1) ) : 0;
	}

	return resp;	
}

int main (){
	// FAST_IO();

	long long k ;
	cin >> k;

	auto check = [&](long long j) {
		if (j == 0) return 0LL;
		num.clear();
		while(j) {
			num.push_back(j%10);
			j /= 10;
		}
		long long resp = 0;
		for (int j = num.size() - 1; j >= 0; --j) {
			bool init = j == num.size() - 1;
			for (int i = 1; i <= (init ? num.back() : 9); ++i) {
				resp += dp(j-1, i, init && i == num.back());
			}
		}

		return resp;
	};

	long long lo = 0;
	long long hi = 3234566667LL;
	while(lo < hi) {
		long long mid = (lo + hi)/2;
		if (check(mid) < k) lo = mid + 1;
		else hi = mid;
	}

	cout << lo << endl;

	return 0;
}
