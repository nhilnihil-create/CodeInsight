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
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 30;
int n, m, x, y, q, d; ll z, w = 0, sum; int ans = 1;
const int MAX = 510000;
const int MOD = 1000000007;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main(void) {
	cin >> z >> w;
	sum = gcd(z, w);
	for (ll i = 2; sum >= i * i; i++) {
		if (sum % i == 0) {
			ans++;
			while (sum % i == 0) sum /= i;
		}
	}if (sum != 1)ans++;
	cout << ans << endl;
}