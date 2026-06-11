#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cmath>
#include<numeric>
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
	return (n != 1);
}
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll x, ll y) {
	return (x * y) / gcd(x, y);
}

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
int main() {
	//cout << fixed << setprecision(9);
	//freopen("Input.txt.txt","r",stdin);
	//freopen("Output.txt.txt","w",stdout);
	AIA();
	
		ll n;
	cin >> n;
	if (400 <= n && n <= 599) {
		cout << 8;
	}
	else if (600 <= n && n <= 799) {
		cout << 7;
	}
	else if (800 <= n && n <= 999) {
		cout << 6;
	}
	else if (1000 <= n && n <= 1199) {
		cout << 5;
	}
	else if (1200 <= n && n <= 1399) {
		cout << 4;
	}
	else if (1400 <= n && n <= 1599) {
		cout << 3;
	}
	else if (1600 <= n && n <= 1799) {
		cout << 2;
	}
	else if (1800 <= n && n <= 1999) {
		cout << 1;
	}
	
    return 0;
}