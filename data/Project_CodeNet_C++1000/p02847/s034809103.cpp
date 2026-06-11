#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	map<string, int> mp;
	mp["SUN"] = 7;
	mp["MON"] = 6;
	mp["TUE"] = 5;
	mp["WED"] = 4;
	mp["THU"] = 3;
	mp["FRI"] = 2;
	mp["SAT"] = 1;
	string s;
	cin >> s;
	cout << mp[s] << endl;
}
