#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
/*
template<typename... Args>
void print(Args... args) {
	#ifdef LOCAL
	((std::cout << args << " "), ...);
	cout << endl;
	#endif
}
 */
//endregion

/* Notes:
 * Farah </3
 */
const int MAXN = 2e5 + 6;
bool a[MAXN];

int b[MAXN];

int main() {
	#ifdef LOCAL
		setIn("in.txt");
		setOut("out.txt");
	#endif

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = n; i >= 1; i--){
		int sum = 0;
		for(int j = i; j <= n; j += i){
			sum += b[j];
		}

		if(a[i] == 1 && (sum % 2 == 0)){
			b[i] += 1;
		}
		if(a[i] == 0 && (sum % 2 != 0)){
			b[i] += 1;
		}
	}

	int cnt = 0;
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		if(b[i] != 0) cnt++, ans.push_back(i);
	}
	cout << cnt << endl;
	for(auto x : ans){
		cout << x << " ";
	}
}