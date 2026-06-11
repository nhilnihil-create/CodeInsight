#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvlong long vector<vector<long long>>
#define vvc vector<vector<char>>
#define vlong long vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;

int main() {
	long long colors = 0;
	long long N; cin >> N;
	vector<long long> a(3, 0);
	long long ans = 1;
	for (int i = 0; i < N; i++) {
		sort(ALL(a));
		long long x; cin >> x;
		if (x == 0) colors++;
		long long cnt = 0;
		if (x == a[0]) cnt++;
		if (x == a[1]) cnt++;
		if (x == a[2]) cnt++;

		if (x == a[0]) {
			a[0]++;
		}
		else {
			if (x == a[1]) {
				a[1]++;
			}
			else {
				if (x == a[2]) {
					a[2]++;
				}
				else {
					cout << 0 << endl;
					return 0;
				}
			}
		}
		ans *= cnt;
		ans %= MOD;
	}

	cout << ans << endl;
}