
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<20)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

int main()
{
	int m;
	string s;

	cin >> m;
	rep(i, m) {
		cin >> s;
		set<string> all;
		all.insert(s);
		for (int j = 1; j < s.size(); j++) {
			string L;
			L = s.substr(0,j);
			string R;
			R = s.substr(j);
			string L2=L, R2=R;
			reverse(L2.begin(),L2.end());
			reverse(R2.begin(),R2.end());
			all.insert(R+L);
			all.insert(R2+L);
			all.insert(L+R2);
			all.insert(L2 + R);
			all.insert(R+L2);
			all.insert(R2+L2);
			all.insert(L2+R2);
		}
		cout << all.size() << endl;
	}
	return 0;
}