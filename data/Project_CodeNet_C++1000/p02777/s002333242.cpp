#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

int32_t main(){
	ios::sync_with_stdio(0);	
	map<string, int> mp;
	string a, b;
	int ai, bi;
	cin >> a >> b >> ai >> bi;
	mp[a] = ai;
	mp[b] = bi;
	string st;
	cin >> st;
	--mp[st];
	cout << mp[a] << " " << mp[b] << endl;
}
