#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int N;

LL A[1 << 20], B[1 << 20];
priority_queue<pair<LL, int> > heap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	FOR (i, N)
		cin >> A[i];
	FOR (i, N)
		cin >> B[i];
		
	while (!heap.empty())
		heap.pop();
		
	FOR (i, N)
		heap.push(make_pair(B[i], i));
		
	LL ret = 0LL;
	while (!heap.empty()) {
		pair<LL, int> val = heap.top();
		heap.pop();
		int idx = val.second;
		if (A[idx] == B[idx])
			continue;
		
		int idxLeft = idx - 1;
		if (idxLeft < 0)
			idxLeft = N - 1;
		int idxRight = idx + 1;
		if (idxRight == N)
			idxRight = 0;
			
		LL sum = B[idxLeft] + B[idxRight];
		if (sum <= 0) {
			ret = -1;
			break;
		}
		LL times = (B[idx] - A[idx]) / sum;
		if (times == 0LL)
			times = 1LL;
		ret += times;
			
		B[idx] -= times * sum;
		if (B[idx] < A[idx]) {
			ret = -1;
			break;
		}
		
		heap.push(make_pair(B[idx], idx));
	}
	
	cout << ret << endl;
	return 0;
}