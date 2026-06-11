#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define FOR(i,a,b)  for(int i=(a); i< (b); ++i)
#define RFOR(i,b,a) for(int i=(b);i>=(a);i--)
#define REP(i,a,b)  for(int i=(a); i<=(b); ++i)
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
template<typename T>
void PrArr(const T a[] , int len){
	for(int i = 0;i <= len; i++)cout << a[i] << " ";
	cout << endl;
}
template<typename T>
void PrVec(const vector<T> a){
	for(auto it : a)cout << it << " ";
	cout << endl;
}
const int MAX = 0x7ffffff;
const int MIN = 0xcf;
const int N = 10000007;
int test;
bool vis[N];
void slove()
{
	int n;cin >> n;
	ll ans = 0;
	for(int x = 1;x <= n;x ++)
	{
		int y = n / x;
		ans += (ll)y * (y + 1) * x / 2;
	}
	cout << ans << endl;
}
int main()
{
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed; // 在iomanip中
#endif
	SIS;slove();
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}