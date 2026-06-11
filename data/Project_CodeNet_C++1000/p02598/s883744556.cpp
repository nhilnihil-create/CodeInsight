#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#include <ctime>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e9;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(ll i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using Graph = vector<vector<ll>>;

#define ketasitei setprecision(15) //15桁表示

const ll MOD = 1000000007;
const double PI = 3.1415926535897932;

bool isOK(ll x,ll k,vector<ll> a)
{
	ll sum = 0;
	rep(i, a.size())
	{
		sum += (a[i] + x - 1) / x - 1;
	}
	if (sum <= k)
		return true;
	return false;
}


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	
	ll ok = 1000000001;
	ll ng = 0;

	while (abs(ok - ng) > 1)
	{
		ll mid = (ok + ng) / 2;
		if (isOK(mid,k,a))
		{
			ok = mid;
		}
		else
		{
			ng = mid;
		}
	}

	cout << ok << endl;
	
	//ll n;
	//ll bits = (1 << n) - 1;
	////全部0の場合も調べたいのなら条件を変更するか、別途その分だけプログラムを書く
	//while (bits)
	//{
	//	ll tmp = bits;
	//	for (int i = 0; i < n; i++)
	//	{
	//		if ((tmp >> i) & 1)
	//		{
	//			func();
	//		}
	//		else
	//		{

	//		}
	//	}

	//	bits--;
	//}

	return 0;
}