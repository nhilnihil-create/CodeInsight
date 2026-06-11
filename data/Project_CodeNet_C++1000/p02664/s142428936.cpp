#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <vector>
#define task ""
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e3 + 2;
string s;

void Read(){
	cin >> s;
}

void Solve(){
	int ans = 0;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '?')
			s[i] = 'D';
	cout << s;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(task".INP", "r", stdin);
//	freopen(task".OUT", "w", stdout);
	Read();
	Solve();
}
