#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	map<vector<int>,long long> mp;
	// nyuryoku
	int n;
	cin >> n;
	vector<int> vec(26);
	for(int i=0;i<n;i++){
		vector<int> vec(26,0);
		cin >> s;
		for(int i=0;i<10;i++){
			vec[s[i]-'a']++;
		}
		mp[vec]++;
	}
	// keisan
	LL sum = 0;
	for(auto x:mp){
		sum += x.second*(x.second - 1)/2;
	}
	cout << sum;
	// syutsuryoku
}