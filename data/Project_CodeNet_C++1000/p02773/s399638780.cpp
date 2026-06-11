#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;
string s;

int main(void){
	cin >> n;
	unordered_map<string, int> mp;
	int maxv = 0;
	rep(i, n){
		cin >> s;
		maxv = max(maxv, ++mp[s]);
	}
	priority_queue<string, vector<string>, greater<string>> q;
	for(auto i : mp){
		if(i.second == maxv) q.push(i.first);
	}
	while(!q.empty()){
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}
