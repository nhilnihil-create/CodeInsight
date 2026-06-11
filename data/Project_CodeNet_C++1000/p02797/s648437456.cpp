#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
#include<numeric>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define rep(i, k) for (i = 0; i < k; i++) 
typedef long long ll;
typedef pair<ll, ll> l_l;
int i, j;

ll b, k, n = 0, z = 0,s, x, y, a[200005] = {};
	vector<ll> v,vec;
int main() {
	cin >> n >> k >> s;
	
	rep(i, n) {
		if (i < k)cout << s << " ";
		else {
			if(s==1000000000)cout << 1 << " ";
			else cout << s+1 << " ";
		}
	}
	return 0;

}
