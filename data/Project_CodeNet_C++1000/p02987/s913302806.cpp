#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	string s;
	cin >> s;

	map<char, int>  str;
	rep(i, 4) {
		str[s[i]]++;
	}
	if (str.size() != 2) {
		cout << "No\n";
		return 0;
	}
	rep(i, 4) {
		if (str[s[i]] != 2) {
			cout << "No\\n";
			return 0;
		}
	}
	cout << "Yes\n";

	return 0;
}