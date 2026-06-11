#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<stack>
#include<map>
#include<random>
#include<queue>
#include<iterator>
#include<bitset>
#include<unordered_set>
#include<set>

using namespace std;
#define ll long long
#define endl "\n"
const int dx[] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 };
const int dy[] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 };
const ll integer = pow(2, 32) - 1; // 4294967295
#define N 8010000
#define TC int t;cin>>t;for(int T=1;T<=t;T++)
#define mod 1000000007
#define PI acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
void AIA() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isprime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}
ll prim(ll n) {
	for (int i = 2; i * i <= n; i++) {
		if (i % n == 0) {
			return i;
		}
	}
}
//cout<<fixed<<setprecision(20);
// freopen("stand.in","r",stdin);
// freopen("stand.out","w",stdout);

/*
 _____________              __                ___        ___       ___________________________     ____        ____
|             |            /\ \              |   |      |   |     |                           |    \   \      /   /
|   __________|           / /\ \             |   |      |   |     |      _____      _____     |     \   \    /   /
|  |                     / /  \ \            |   |      |   |     |     |     |    |     |    |      \   \  /   /
|  |                    / /    \ \           |   |      |   |     |     |     |    |     |    |       \   \/   /
|  |______             / /      \ \          |   |______|   |     |     |     |    |     |    |        \      /
|         |           / /        \ \         |              |     |     |     |    |     |    |         \    /
|   ______|          / /          \ \        |    ______    |     |     |     |    |     |    |          |  |
|  |                / /============\ \       |   |      |   |     |     |     |    |     |    |          |  |
|  |               / /==============\ \      |   |      |   |     |     |     |    |     |    |          |  |
|  |              / /                \ \     |   |      |   |     |     |     |    |     |    |          |  |
|  |             / /                  \ \    |   |      |   |     |     |     |    |     |    |          |  |
|__|            /_/                    \_\   |___|      |___|     |_____|     |____|     |____|          |__|

										  <<<<<<<<<<< NEVER GIVE UP !! >>>>>>>>>>>
										<<<<<<<< YOU CAN DO IT IF YOU WANT !! >>>>>>>>
										 <<<<<<<<< BELIEVE IN YOURSELF !! >>>>>>>>>

*/

int  main() {
	//cout << fixed << setprecision(9);
	//freopen("stand.in","r",stdin);
	//freopen("stand.out","w",stdout);

	AIA();

	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			s[i] = 'D';
		}
	}
	cout << s;
	return 0;
}
