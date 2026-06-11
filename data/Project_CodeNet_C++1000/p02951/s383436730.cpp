//#define _GLIBCXX_DEBUG
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<string>
#include<bitset>
#include<random>
#include<ctime>
using namespace std;
typedef long long ll;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << c - min(a - b, c);
}
