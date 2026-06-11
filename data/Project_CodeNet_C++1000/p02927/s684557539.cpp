#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
const auto MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;


int n, m, a, b, c;
string s, t;

int main() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int ue = i / 10;
		int sita = i % 10;
		if (ue < 2 || sita < 2)continue;
		if (ue*sita > n)continue;
		cnt++;
	}
	cout << cnt << endl;
}