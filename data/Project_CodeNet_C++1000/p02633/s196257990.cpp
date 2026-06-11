#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef unsigned long long ll;
typedef long double ld;
const ll INF = 1LL << 60;
const int inf = 1 << 25;
ll n, m, x, y, q, d, z, w, sum = 0, ans = 0;
const int MOD = 1000000007;
vector<int> a, b;
priority_queue<pair<ll, int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
int main(void) {
	cin >> n;
	req(k, 360) {
		if (n * k % 360 == 0) {
			cout << k << endl;
			return 0;
		}
	}
}