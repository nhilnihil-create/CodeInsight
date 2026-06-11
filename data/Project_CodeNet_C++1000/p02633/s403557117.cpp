#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif


const int MAXN = 100;
//#define int long long
const int INF = 1e9;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int x;
	cin >> x;

	auto gcd = [](int a, int b){
		while (a){
			b %= a;
			swap(a, b);
		}
		return b;
	};

	cout << 360 / gcd(360, x) << '\n';

    return 0;
}
