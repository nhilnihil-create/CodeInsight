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
int test;
void slove()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n ;i ++)cin>> a[i];
	sort(a.begin() + 1,a.begin() + n + 1);
	ll ans = 0;
	int k = n / 2;
	for(int i = k + 2;i <= n - 1;i ++)
	{
		ans += 2*(ll)a[i];
	}	
	if(n > 1)ans += a[n];
	if(n > 2){
		if(n & 1)ans += a[k + 1];
		else ans += 2 * a[k + 1];
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