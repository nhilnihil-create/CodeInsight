#include<bits/stdc++.h>
using namespace std;

long long N;
map<string, long long> num;
int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		string s;
		cin >> s;
		num[s]++;
	}

	long long maxi = 0;
	for(auto item: num) {
		maxi = max(maxi, item.second);
	}

	vector<string> ans;
	for(auto item: num) {
		if(item.second == maxi) {
			ans.push_back(item.first);
		}
	}

	sort(ans.begin(), ans.end());
	for(long long i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}
