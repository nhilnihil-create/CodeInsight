#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
int n, m, x, y;ll z = 0, w, h, sum = 0, ans = 0;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main(void) {
	cin >> n >> m;
	priority_queue<int> pq;
	rep(i, n) {
		cin >> x;
		pq.push(x);
	}
	rep(i, m) {
		y = pq.top(); pq.pop();
		pq.push(y / 2);
	}
	while (!pq.empty()) {
		y = pq.top(); pq.pop();
		ans += y;
	}cout << ans << endl;
}