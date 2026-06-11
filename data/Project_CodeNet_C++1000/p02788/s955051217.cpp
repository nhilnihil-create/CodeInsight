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

int main (){
	// FAST_IO();

	long long n, d, a;
	cin >> n >> d >> a;

	vector<long long> acc(n);
	vector<pair<long long, long long>> in(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &in[i].first, &in[i].second);
	}

	sort(in.begin(), in.end());

	long long power = 0;
	long long resp = 0;
	for (int i = 0; i < n; ++i) {
		power += acc[i];

		int j = upper_bound(in.begin(), in.end(), make_pair(in[i].first + 2*d + 1, 0LL)) - in.begin();
		long long add = 0;

		if (in[i].second > power) {
			long long diff = in[i].second - power;
			add = (diff + a - 1)/a;
			resp += add;
			add *= a;
		}
		power += add;

		if (j < n) {
			acc[j] -= add;
		}
	}

	cout << resp << endl;

	return 0;
}
