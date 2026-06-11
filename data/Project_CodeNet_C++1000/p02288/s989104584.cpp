#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Mod (int)1000000007
#define INFTY (int)INT_MAX
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Part(vec, b, e) vec.begin() + b, vec.begin() + e
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(S, s) S.find(s) != string::npos

void build_heap(vector<int> &heap, int H) {
	for (int i = H / 2; i >= 1; i--) {
		int r = i, k = r * 2;
		while (k <= H) {
			if (k < H && heap[k + 1] > heap[k]) k++;
			if (heap[r] > heap[k]) break;
			swap(heap[r], heap[k]);
			r = k, k = r * 2;
		}
	}
}

int main() {
	int H;
	cin >> H;
	vector<int> heap(H + 1);
	for (int i = 1; i <= H; i++) cin >> heap[i];
	build_heap(heap, H);
	for (int i = 1; i <= H; i++) {
		cout << " " << heap[i];
	}
	cout << endl;
	return 0;
}
