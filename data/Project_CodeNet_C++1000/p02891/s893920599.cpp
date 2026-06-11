#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	ll k;
	cin >> s >> k;
	ll index = 0;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == s[i + 1]) {
			index++;
		}
	}
	if (index == s.size() - 1) {
		cout << s.size() * k / 2 << endl;
		return 0;
	}

	else {
		if (s[0] != s[s.size() - 1]) {
			ll index = 1;
			ll count = 0;
			for (int i = 0; i < s.size()-1; i++) {
				if (s[i] == s[i + 1]) {
					index++;
				}
				else {
					count += index / 2;
					index = 1;
				}
			}
			count += index / 2;
			cout << count * k << endl;
		}
		else {
			ll a = 1;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != s[i + 1]) {
					break;
				}
				a++;
			}
			
			ll b = 1;
			for (int j = s.size() - 1; j > 0; j--) {
				if (s[j] != s[j - 1]) {
					break;
				}
				b++;
			}
			ll count = 0;
			ll index = 1;
			for (int i = a; i <s.size()-b; i++) {
				if (s[i] == s[i + 1]) {
					index++;
				}
				else {
					count += index / 2;
					index = 1;
				}
			}
			count += index / 2;
			

			cout << a/2 + b/2  + (a+b)/2*(k-1) + count*k<< endl;
		}
	}
	return 0;

}