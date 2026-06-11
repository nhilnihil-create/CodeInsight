#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

template <class T>
void printArray(vector<T> arr) {for (T a: arr) cout << a << '\n';}
void printVerdict(bool verdict) {cout << (verdict ? "APPROVED": "DENIED") << '\n';}
void printDecimal(double d) {printf("%.9f\n", d);}
bool inrange(int val, int start, int end) {return val >=start && val <= end;}
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) {cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';}
template <class T1, class T2>
void printPair(pair<T1, T2> p) {cout << p.first << " " << p.second << '\n';}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<string> ret;
	map<string, int> count;
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i<n; i++) {
		string temp; cin >> temp;
		if (!present(count, temp)) count[temp] = 1;
		else count[temp]++;
		cnt = max(cnt, count[temp]);
	}
	auto it = count.begin();
	while (it != count.end()) {
		if (it->second == cnt) ret.push_back(it->first);
		it++;
	}
	sort(ret.begin(), ret.end());
	printArray(ret);
} 


