#include <bits/stdc++.h>
using namespace std;

int main () {
  	long long N, ans = 0;
  	cin >> N;
  	map<vector<long long>, long long> mp;
  	for (long long i = 0; i < N; i++) {
      	string s;
      	cin >> s;
      	vector<long long> tmp;
      	for (long long j = 0; j < 10; j++) {
          	tmp.push_back(s[j]-'a');
        }
      	sort(tmp.begin(),tmp.end());
      	mp[tmp]++;
    }
  	for (auto i : mp) {
      	ans += i.second * (i.second-1) / 2;
    }
  	cout << ans << endl;
  	return 0;
}
      	