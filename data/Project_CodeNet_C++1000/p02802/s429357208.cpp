#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int Max = 10 + 1e8;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<bool> drn(n,false);
	int ac = 0;
	int wa = 0;
	vector<int> miss(n);
	rep(i, m) {
		int a;
		string s;
		cin >> a >> s;
		a--;
		if (s == "AC") {
			if (drn[a] == false) {
				drn[a] = true;
				ac++;
				wa += miss[a];
			}
		}
		if (s == "WA") {
			if (drn[a] == false) {
				miss[a]++;
			}
		}
		
	}
	cout << ac << " " << wa;
}