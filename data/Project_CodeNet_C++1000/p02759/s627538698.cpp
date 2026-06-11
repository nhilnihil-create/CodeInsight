//Apparat : drobucs, aleonov, vit_72
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>

//pragma warning(disable : 4996)
//#pragma GCC optimize("O3")

#define nptr nullptr
#define all(x) (x).begin(), (x).end()
#define drobucs ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define ff first
#define ss second
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn = (int)2e5 + 13;
const ll INFL = 9223372036854775807;
const int INF = 2147483647;
const ll MOD = (int)1e9 + 7, MOD2 = 1e9 + 21;//1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9 + 93
const ll base = 101, base2 = 37;
const long double pi = 3.1415926535897932;



int main() {
	drobucs;
	
	ll n;
	cin >> n;
	cout << n / 2 + n % 2;
	return 0;
}