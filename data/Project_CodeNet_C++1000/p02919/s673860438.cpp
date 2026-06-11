
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main()
{
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		p--;
		c[p] = i;
	}

	multiset<int> s;
	
	
	for (int i = 0; i < 2; i++) {
		s.insert(-1);
		s.insert(n);
	}

	ll ans = 0;

	for (int i = n-1; i >=0; i--) {
		
		auto it = s.lower_bound(c[i]);
		it++;
		it++;
		vector<int> x(4);

		for (int j = 0; j < 4; j++) {
			it--;
			x[j] = *it;
			//cout << x[j] << " ";
		}
		//cout << endl;

		ll cnt =1LL * (x[0] - x[1]) * (c[i] - x[2]);
		cnt += 1LL *(x[2] - x[3]) * (x[1] - c[i]);
		
		ans += cnt * (i + 1);
		s.insert(c[i]);
	}
	cout << ans << endl;

}  

