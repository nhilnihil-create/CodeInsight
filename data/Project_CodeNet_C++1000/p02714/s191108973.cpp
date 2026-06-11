#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<utility>
#include<functional>
#include<cfenv>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define vint vector<ll>
#define vvint vector<vint>
#define P pair<ll,ll>
#define INT_MAX 2147483647
#define MOD 1000000007
#define PI 3.14159265358979323846
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

#define MAX 1000000000000


int main(void) {
	ll n; cin >> n; n--;
	string s; cin >> s;
	map<char, ll> mp;

	ll ng=0;
	rep(i, s.size()) {
		mp[s[i]]++;
	}
	for (ll i = 1; i <= n / 2; i++) {
		for(ll j = 0; j <= n - 2 * i; j++) {
			if (s[j] != s[j + i] && s[j + i] != s[j + 2 * i] && s[j] != s[j + 2 * i]) {
				ng++;
			}
		}
	}
	cout << mp['R'] * mp['G'] * mp['B'] - ng << endl;
	return 0;
}
