#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	map<string, long long> m;
	for(int i = 0;i < n;++i){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		m[str]++;
	}
	
	long long ans = 0;
	for(pair<string, long long> e : m)
		ans += ((e.second * (e.second-1)) / 2);
	cout << ans;
}
