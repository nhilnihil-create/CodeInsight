#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main(void) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll count = 0;
	for (int i = 0; i < 1000; i++) {
		int c[3] = {(i/100)%10,(i/10)%10,i%10};
		int f = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] - '0' == c[f]) {
				f++;
			}
			if (f == 3) {
				break;
			}
		}
		if (f == 3) {
			count++;
		}
		
	}
	cout << count << endl;
	
	return 0;
}